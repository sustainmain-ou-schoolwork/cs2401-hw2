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
    // copy new data
    used = other.used;
    capacity = other.capacity;

    data = new Song[capacity];
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        data[i] = other.data[i];
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

    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        data[i] = other.data[i];
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
    if (used == 0) {
        return;
    }

    if (is_item()) {
        for (size_t i = current_index; i < static_cast<size_t>(used - 1); i++) {
            data[i] = data[i + 1];
        }
    }

    used--;
}
void Playlist::insert(const Song& s) {
    if (used >= capacity) {
        resize();
    }

    if (is_item()) {
        // insert the Song before the Song at current_index
        for (size_t i = used; i > static_cast<size_t>(current_index); i--) {
            data[i] = data[i - 1];
        }

        data[current_index] = s;
    }
    else {
        // insert the Song at the beginning of the Playlist
        for (size_t i = used; i > 0; i--) {
            data[i] = data[i - 1];
        }

        data[0] = s;
    }

    used++;
    advance();
}
void Playlist::attach(const Song& s) {
    if (used >= capacity) {
        resize();
    }

    if (is_item()) {
        // insert the Song after the Song at current_index
        for (size_t i = used; i > static_cast<size_t>(current_index + 1); i--) {
            data[i] = data[i - 1];
        }

        data[current_index + 1] = s;
    }
    else {
        // insert the Song at the end of the Playlist
        data[used] = s;
    }

    used++;
    advance();
}

void Playlist::show_all(std::ostream& outs)const {
    std::cout << '\n';
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        std::cout << "Song " << (i + 1) << '\n';
        outs << data[i];
        std::cout << std::endl;
    }
}
void Playlist::releaseDate_sort() {
    bool done = false;
    size_t i;
    Song tmp;

    // bubble sort
    while (!done) {
        done = true;
        for (i = used - 1; i > 0; --i) {
            if (data[i].get_release() < data[i - 1].get_release()) {
                done = false;
                tmp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = tmp;
            }
        }
    }
}
void Playlist::artist_sort() {
    bool done = false;
    size_t i;
    Song tmp;

    // bubble sort
    while (!done) {
        done = true;
        for (i = used - 1; i > 0; --i) {
            if (data[i].get_artist() < data[i - 1].get_artist()) {
                done = false;
                tmp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = tmp;
            }
        }
    }
}
Song Playlist::find_song(const std::string& name)const {
    // look through each Song in the Playlist
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        // if the name matches, return the Song
        if (data[i].get_name() == name) {
            return data[i];
        }
    }

    // if no match was found, return the default Song
    Song tmp;
    return tmp;
}
bool Playlist::is_song(const Song& s) const {
    // look through each Song in the Playlist
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        // if the Song values match, return true
        if (data[i] == s) {
            return true;
        }
    }

    return false;
}

void Playlist::load(std::istream& ins) {
    Song tmp;

    // Load each song from the file
    while (ins >> tmp) {
        attach(tmp);
    }
}
void Playlist::save(std::ostream& outs)const {
    // output each Song
    for (size_t i = 0; i < static_cast<size_t>(used); i++) {
        outs << data[i];
    }
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