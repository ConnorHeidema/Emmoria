#ifndef I_OBSERVER_HPP
#define I_OBSERVER_HPP

/**
 * The gridded observer will be notified when a
 * subject has changed their tilemap picture
 */
class IGriddedObserver
{
public:
	virtual void OnNotify(int x, int y) = 0;
};

#endif
