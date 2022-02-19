#include "Playlist.h"


Playlist::Playlist() {
    used = 0;
    capacity = 5;
    current_index = 0;

    data = new Song[capacity];
}

// The Big 3
Playlist::~Playlist() {
    delete []data;
}
Playlist::Playlist(const Playlist& other) {
    used = other.used;
    capacity = other.capacity;

    data = new Song[capacity];
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        data[i] = other.data[i];  // todo: make this do a deep copy of each Song
    }
}
void Playlist::operator = (const Playlist& other) {
    if (this == &other) {
        return;
    }

    // delete old data
    delete []data;

    // copy new data
    used = other.used;
    capacity = other.capacity;

    for (size_t i = 0; i < used; i++) {
        data[i] = other.data[i];  // todo: make this do a deep copy of each Song
    }
}

// Functions for the internal iterator
void Playlist::start() {
    current_index = 0;
}
void Playlist::advance() {
    current_index++;
}
bool Playlist::is_item()const {
    return current_index < used;
}
Song Playlist::current()const {
    return data[current_index];
}

// Other useful things the user may want to do
void Playlist::remove_current() {

}
void Playlist::insert(const Song& s) {

}
void Playlist::attach(const Song& s) {

}

void Playlist::show_all(std::ostream& outs)const {

}
void Playlist::releaseDate_sort() {

}
void Playlist::artist_sort() {

}
Song Playlist::find_song(const std::string& name)const {

}
bool Playlist::is_song(const Song& s) const {

}

void Playlist::load(std::istream& ins) {

}
void Playlist::save(std::ostream& outs)const {

}


void Playlist::resize() {
    capacity += 5;

    Song* tmp;
    tmp = new Song[capacity];
    
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        tmp[i] = data[i];
    }

    delete []data;
    data = tmp;
}