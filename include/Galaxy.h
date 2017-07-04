#include <vector>
#include <Star.h>

class Galaxy
{
public:

  /// Constructor 
  Galaxy(std::vector<Star> stars)
   : stars(stars)
  {}

  /// Return total mass of Galaxy
  double get_mass() const;

private:

  /// List of star members
  std::vector<Star> stars;

};

