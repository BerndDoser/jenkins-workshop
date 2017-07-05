#!groovy

pipeline {
  agent {
    docker {
      image 'bernddoser/docker-devel-cpp:ubuntu-17.04-gcc-7-gtest-1.8.0-doxygen-1.8.13'
      label 'docker-nodes'
    }
  }
  stages {
    stage('Build') {
      steps {
        sh '''
          mkdir -p build
          cd build
          cmake ..
          make
        '''
      }
    }
    stage('Test') {
      steps {
        script {
          try {
            sh '''
              cd build
              make test
            '''
          } catch (err) {
            echo "Failed: ${err}"
          } finally {
            step([
              $class: 'XUnitBuilder',
              thresholds: [[$class: 'FailedThreshold', unstableThreshold: '1']],
              tools: [[$class: 'GoogleTestType', pattern: 'build/Testing/*.xml']]
            ])
          }
        }
      }
    }
    stage('Doxygen') {
      steps {
        sh '''
          cd build
          make doc
        '''
        publishHTML( target: [
          allowMissing: false,
          alwaysLinkToLastBuild: false,
          keepAll: true,
          reportName: 'Doxygen',
          reportDir: 'build/docs/html/doxygen/html-full',
          reportFiles: 'index.xhtml'
        ])
      }
    }
    stage('Deploy') {
      steps {
        sh '''
          cd build
          make package
        '''
      }
    }
  }
  post {
    success {
      archiveArtifacts artifacts: "build/jenkins_workshop-*-Linux.deb", fingerprint: true
      mail to: 'bernd.doser@h-its.org', subject: "SUCCESS: ${currentBuild.fullDisplayName}", body: "All fine."
    }
    failure {
      mail to: 'bernd.doser@h-its.org', subject: "FAILURE: ${currentBuild.fullDisplayName}", body: "Error: ${env.BUILD_URL}"
    }
  }
}

