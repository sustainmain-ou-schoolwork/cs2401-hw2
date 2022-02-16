#include "Song.h"


Song::Song() {
    name = "";
    release = Date();
    artist = "";
}
std::string Song::get_name()const {

}
Date Song::get_release()const {

}
std::string Song::get_artist()const {

}

bool Song::operator == (const Song& other)const {

}
bool Song::operator != (const Song& other)const {

}

void Song::input(std::istream& ins) {
    std::string lineIn;
    getline(ins, lineIn);
    name = lineIn;
    ins >> release;
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