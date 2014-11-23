#include "SlotBase.hpp"

namespace QT {
    SlotBase::SlotBase()
    {
        this->muted = false;
    }

    void SlotBase::mute(bool mute) {
        this->muted = mute;
    }
}
