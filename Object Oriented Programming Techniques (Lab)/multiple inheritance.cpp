#include <iostream>
#include <string>

using namespace std;
class AudioPlayer {
protected:
    string song_title;
    string artist;

public:
    AudioPlayer(string st, string a) : song_title(st), artist(a) {}

    void playAudio() {
        cout << "Playing song: " << song_title << " by " << artist << endl;
    }
};
class VideoPlayer {
protected:
    string video_title;
    string director;

public:
    VideoPlayer(string vt, string d) : video_title(vt), director(d) {}

    void playVideo() {
        cout << "Playing video: " << video_title << " directed by " << director << endl;
    }
};

class MediaPlayer : public AudioPlayer, public VideoPlayer {
public:
    MediaPlayer(string st, string a, string vt, string d)
        : AudioPlayer(st, a), VideoPlayer(vt, d) {}


    void play() {
        playAudio(); 
        playVideo();
    }
};

int main() {
    MediaPlayer player("Shape of You", "Ed Sheeran", "Inception", "Christopher Nolan");
    player.play(); 

    return 0;
}

