#include "Playlist.h"


Playlist::Playlist() {

}

// The Big 3
Playlist::~Playlist() {

}
Playlist::Playlist(const Playlist& other) {

}
void Playlist::operator = (const Playlist& other) {

}

// Functions for the internal iterator
void Playlist::start() {

}
void Playlist::advance() {

}
bool Playlist::is_item()const {

}
Song Playlist::current()const {

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

}