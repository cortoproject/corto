#ifndef SLOTBASE_HPP
#define SLOTBASE_HPP

namespace QT {
class SlotBase {
public:
    SlotBase();
    void mute(bool mute);
protected:
    bool muted;
};
}

#endif // SLOTBASE_HPP
