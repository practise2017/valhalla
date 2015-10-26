#ifndef VALHALLA_BALDR_ADMIN_H_
#define VALHALLA_BALDR_ADMIN_H_

#include <stdint.h>

#include <valhalla/midgard/util.h>

namespace valhalla {
namespace baldr {

constexpr size_t kStateIso = 3;
constexpr size_t kCountryIso = 2;

/**
 * Holds a generic admin with state and country iso and text. Text is stored
 * in the GraphTile text list and the offset is stored within the admin.  This
 * is a read only base class.
 */
class Admin {
 public:

  /**
   * Get the country ISO3166-1 code.
   * @return  Returns the ISO country code.
   */
  const std::string country_iso() const;

  /**
   * Get the state ISO code. Country ISO + dash + state ISO will give
   * you ISO3166-2 for state.
   * @return  Returns the state ISO code.
   */
  const std::string state_iso() const;

  /**
   * Get the offset into the GraphTile text list for the state text associated
   * with the admin.
   * @return  Returns the text offset.
   */
  uint32_t state_offset() const;

  /**
   * Get the offset into the GraphTile text list for the country text associated
   * with the admin.
   * @return  Returns the text offset.
   */
  uint32_t country_offset() const;

 protected:
  // Constructor
  Admin(const uint32_t country_offset, const uint32_t state_offset,
        const std::string& country_iso, const std::string& state_iso);

  uint32_t country_offset_;         // country name offset
  uint32_t state_offset_;           // state name offset
  char country_iso_[kCountryIso];   // country ISO3166-1
  char state_iso_[kStateIso];       // state ISO3166-2
  char spare_[3];                   // spare for byte alignment
};

}
}

#endif  // VALHALLA_BALDR_ADMIN_H_
