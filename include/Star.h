#include <array>

class Star
{
public:

  /// Constructor
  Star(std::array<double, 3> const& position, double mass)
   : position(position), mass(mass)
  {}

  /// Return mass mass
  double get_mass() const { return mass; }

private:

  /// Position of the star
  std::array<double, 3> position;

  /// Mass of the star
  double mass;

};

