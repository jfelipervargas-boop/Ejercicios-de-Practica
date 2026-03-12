#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(std::string a, std::string b) {
    if (a.size() != b.size()) {
        throw std::domain_error("length mismatch");
    }

    int count = 0;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            count++;
        }
    }

    return count;
}

}
