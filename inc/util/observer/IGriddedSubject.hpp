#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include "util/observer/IGriddedObserver.hpp"

#include <functional>
#include <vector>
#include <memory>

/**
 * A gridded subject will notify a gridded
 * observer when the picture has been changed
 * and pass the location of that change.
 */
class IGriddedSubject
{
public:

  IGriddedSubject(int x, int y) : m_xIndex(x), m_yIndex(y) {}

	/**
	 * The subject interface will notify pObservers when a particular event happens
	 */
	void RegisterObserver(std::shared_ptr<IGriddedObserver> pObserver)
  {
    pObservers.emplace_back(pObserver);
  }

  void NotifyObservers()
  {
    for (auto& pObserver : pObservers)
    {
      pObserver->OnNotify(m_xIndex, m_yIndex);
    }
  }

  int m_xIndex;
  int m_yIndex;
private:
  std::vector<std::shared_ptr<IGriddedObserver>> pObservers;
};

#endif
