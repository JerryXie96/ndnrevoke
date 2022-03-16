#ifndef NDNREVOKE_RK_MEMORY_HPP
#define NDNREVOKE_RK_MEMORY_HPP

#include "rk-storage.hpp"

namespace ndnrevoke {
namespace rk {

class RkMemory : public RkStorage
{
public:
  RkMemory(const Name& rkName = Name(), const std::string& path = "");
  const static std::string STORAGE_TYPE;

public:
  /**
   * @throw if request cannot be fetched from underlying data storage
   */
  RevocationState
  getRevocationState(const StateId& stateId) override;

  /**
   * @throw if there is an existing RevocationState with the same State ID
   */
  void
  addRevocationState(const RevocationState& state) override;

  void
  updateRevocationState(const RevocationState& state) override;

  void
  deleteRevocationState(const StateId& stateId) override;

  std::list<RevocationState>
  listAllRevocationStates() override;

  std::list<RevocationState>
  listAllRevocationStates(const Name& rkName) override;

private:
  std::map<StateId, RevocationState> m_revocationStates;
};

} // namespace rk
} // namespace ndnrevoke

#endif // NDNREVOKE_RK_MEMORY_HPP