#pragma once

struct Cell {
    long long x;
    long long y;

    bool operator<(const Cell& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};