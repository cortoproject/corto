#include "Qt/_meta.hpp"

extern "C" {
int hyvemain(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    hyve::import("lang4cpp");
    return QT::load();
}
}
