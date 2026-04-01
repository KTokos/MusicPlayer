# Music Playlist Manager

A C++ console application that manages music playlists using a **Doubly Linked List** data structure. This program allows users to organize their music library, create filtered playlists by artist or genre, shuffle songs, and maintain a history of recently played tracks with persistent CSV storage.

---

## Features

* **Dynamic Playlists:** Manage a "Default" playlist along with specialized lists for Artists, Genres, Recently Played, and Shuffled tracks.
* **Persistent Storage:** Automatically loads `playlist.csv` on startup and saves all active playlists back to CSV files upon exit.
* **Advanced Filtering:** Create sub-playlists by searching for specific Artists or Genres within the master library.
* **Shuffle Logic:** Generate a randomized queue of songs from any existing playlist.
* **Playback Tracking:** "Playing" a song automatically adds it to a "Recently Played" list.
* **Custom Exports:** Export any specific playlist to a user-defined `.csv` filename at any time.

## Technical Details

The core of this application is a custom **Doubly Linked List** implementation. This choice of data structure provides:
* **Efficient Deletion:** Removing a song from the middle of the list is faster than a standard array or vector.
* **Bidirectional Navigation:** The structure supports moving both forward and backward through the playlist (ideal for "Next" and "Previous" song logic).
* **Memory Management:** Dynamic allocation ensures the playlist grows and shrinks exactly as needed.

## Prerequisites

* **Compiler:** A C++ compiler (GCC/MinGW, Clang, or MSVC).
* **Operating System:** Windows (The code utilizes the `Sleep()` function from the Windows API for UI timing).
* **Data Source:** A file named `playlist.csv` must exist in the root directory for the initial data load.

## Getting Started

1.  **Clone the repository** (or save the files to a local directory).
2.  **Compile the program** using your terminal:
    ```bash
    g++ main.cpp doublyLinkedList.cpp -o PlaylistManager
    ```
3.  **Run the application**:
    ```bash
    ./PlaylistManager
    ```

## File Structure

* `main.cpp`: The entry point containing the menu loop and state management for "unlocked" playlists.
* `doublyLinkedList.h`: Header file defining the `doublyLinkedList` class and its nodes.
* `doublyLinkedList.cpp`: Implementation of the list logic (Add, Delete, Shuffle, Filter, Store, Load).
* `playlist.csv`: The primary database file for the music library.

## How It Works

The program uses a "state-unlock" system. For example, the **Artist Playlist** and **Genre Playlist** menu options only become fully interactive once you have performed a filter operation. On exit, the program checks which playlists were active during the session and saves each to its own dedicated CSV file (e.g., `shuffledPlaylist.csv`).

---
*Developed as a demonstration of Doubly Linked List applications in C++.*
