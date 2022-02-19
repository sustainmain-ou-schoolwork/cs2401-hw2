#include "Song.h"


Song::Song() {
    name = "";
    release = Date();
    artist = "";
}

std::string Song::get_name()const {
    return name;
}

Date Song::get_release()const {
    return release;
}

std::string Song::get_artist()const {
    return artist;
}

bool Song::operator == (const Song& other)const {
    if (name == other.name && release == other.release && artist == other.artist) {
        return true;
    }
    else {
        return false;
    }
}

bool Song::operator != (const Song& other)const {
    return !(this == &other);
}

void Song::input(std::istream& ins) {
    std::string lineIn;

    while (ins.peek() == '\n' || ins.peek() == '\r') {
        ins.ignore();
    }
    getline(ins, lineIn);
    name = lineIn;
    ins >> release;
    while (ins.peek() == '\n' || ins.peek() == '\r') {
        ins.ignore();
    }
    getline(ins, lineIn);
    artist = lineIn;
}

void Song::output(std::ostream& outs)const {
    outs << name << '\n';
    outs << release << '\n';
    outs << artist << std::endl;
}


std::istream& operator >> (std::istream& ins, Song& s) {
    s.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Song& s) {
    s.output(outs);
    return outs;
}