#ifndef SLOTBASE_H
#define SLOTBASE_H

namespace QT {
    class SlotBase {
    public:
        SlotBase();
        void mute(bool mute);
    protected:
        bool muted;
    };
}

#endif // SLOTBASE_H
