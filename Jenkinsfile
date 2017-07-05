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
          make |& tee make.out
        '''
      }
      post {
        always {
          step([
            $class: 'WarningsPublisher', canComputeNew: false, canResolveRelativePaths: false,
            defaultEncoding: '', excludePattern: '', healthy: '', includePattern: '', messagesPattern: '',
            parserConfigurations: [[parserName: 'GNU Make + GNU C Compiler (gcc)', pattern: 'build/make.out']],
            unHealthy: ''
          ])
        }
      }
    }
    stage('Test') {
      steps {
        sh 'cd build && make test'
      }
      post {
        always {
          step([
            $class: 'XUnitBuilder',
            thresholds: [[$class: 'FailedThreshold', unstableThreshold: '1']],
            tools: [[$class: 'GoogleTestType', pattern: 'build/Testing/*.xml']]
          ])
        }
      }
    }
    stage('Doxygen') {
      steps {
        sh 'cd build && make doc'
        publishHTML( target: [
          allowMissing: false,
          alwaysLinkToLastBuild: false,
          keepAll: true,
          reportName: 'Doxygen',
          reportDir: 'build/doxygen/html',
          reportFiles: 'index.html'
        ])
      }
    }
    stage('Deploy') {
      steps {
        sh 'cd build && make package'
      }
    }
  }
  post {
    success {
      archiveArtifacts artifacts: "build/jenkins-workshop-*", fingerprint: true
      mail to: 'bernd.doser@h-its.org', subject: "SUCCESS: ${currentBuild.fullDisplayName}", body: "Success: ${env.BUILD_URL}"
    }
    failure {
      mail to: 'bernd.doser@h-its.org', subject: "FAILURE: ${currentBuild.fullDisplayName}", body: "Failure: ${env.BUILD_URL}"
    }
  }
}

