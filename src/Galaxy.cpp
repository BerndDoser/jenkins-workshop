#include <Galaxy.h>
#include <numeric>

double Galaxy::get_mass() const
{
  double unused;
  return std::accumulate(stars.begin(), stars.end(), 1.0,
         [](double mass , Star const& star) {
           return mass + star.get_mass();
         });
}

