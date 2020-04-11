#include<iostream>
#include<list>
#include<algorithm>
#include<iomanip>
#include<limits>
#include<cctype>

class Song
{
    friend std::ostream &operator<<(std::ostream &os,const Song &s);
private:
    std::string song_name;
    std::string singer_name;
    int rating;
public:
    Song()=default;
    Song(std::string song_name,std::string singer_name,int rating)
        :song_name(song_name),singer_name(singer_name),rating(rating)
        {}
    std::string get_song(){
        return song_name;
    }
    std::string get_singer(){
        return singer_name;
    }
    
    int get_rating(){
        return rating;
    }
    
    bool operator>(const Song &s) const{
       return (this->rating>s.rating);
   }
   
   bool operator==(const Song &s) const{
       return (this->song_name==s.song_name&&this->singer_name==s.singer_name&&this->rating==s.rating);
   }
   
   bool operator=(Song &s){
       this->song_name=s.song_name;
       this->singer_name=s.singer_name;
       this->rating=s.rating;
       return true;
   }
};

std::ostream &operator<<(std::ostream &os,const Song &s)
{
    os<<std::setw(20)<<std::left<<s.song_name
        <<std::setw(30)<<std::left<<s.singer_name
        <<std::setw(3)<<s.rating<<std::endl;
    return os;
}

void display_menu()
{
    std::cout<<"\nF-Play first song"<<std::endl;
    std::cout<<"N-Play next song"<<std::endl;
    std::cout<<"P-Play previous song"<<std::endl;
    std::cout<<"L-Play last song"<<std::endl;
    std::cout<<"A-Add and play a new song"<<std::endl;
    std::cout<<"D-Display the current playlist"<<std::endl;
    std::cout<<"***************************************"<<std::endl;
    std::cout<<"Enter a selection(Q to quit)"<<std::endl;
}

void play_current_song(const Song &s)
{
    //playing followed by song that is playing
    std::cout<<"Playing: "<<std::endl;
    std::cout<<s;
}

void display_playlist(const std::list<Song>&playlist,const Song &current_song)
{
    //displays current playlist and then current song playing
    std::cout<<"Current playlist: "<<std::endl;
    for(auto &s:playlist){
        std::cout<<s;
    }
    play_current_song(current_song);
}

int main()
{
    std::list<Song>playlist{
        {"Mast Magan","Arijit Singh",5},
        {"Duniya","Akhil S",5},
        {"Wolves","Selena Gomez",4},
        {"Faded","Drake",5},
        {"Love Story","Taylor Swift",4}
    };
    
    std::list<Song>::iterator current_song=playlist.begin();
    display_playlist(playlist,*current_song);
    char selection {};
    do
    {
        display_menu();
        std::cin>>selection;
        selection=std::toupper(selection);
        if(selection=='F'){
            std::cout<<"Playing first song for you! "<<std::endl;
            play_current_song(*current_song);
        }
        else if(selection=='N'){
            std::cout<<"Playing next song for you!"<<std::endl;
            current_song++;
            if(current_song==playlist.end()){
                current_song=playlist.begin();
            }
                play_current_song(*current_song);
        }
        else if(selection=='P')
        {
            std::cout<<"Playing previous song for you!"<<std::endl;
            if(current_song==playlist.begin()){
                current_song=playlist.end();
                std::cout<<"Last song is being played."<<std::endl;
            }
                current_song--;
                play_current_song(*current_song);
        }
        else if(selection=='A'){
            std::cout<<"Adding new song at current location and playing it for you!"<<std::endl;
            std::string song;
            std::string artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Enter the song: "<<std::endl;
            getline(std::cin,song);
            std::cout<<"Enter the artist: "<<std::endl;
            getline(std::cin,artist);
            std::cout<<"Enter the rating: "<<std::endl;
            std::cin>>rating;
            Song new_song(song,artist,rating);
            playlist.insert(current_song,new_song);
            current_song--;
            play_current_song(*current_song);
        }
        else if(selection=='D'){
            std::cout<<"Displaying current playlist..wait......"<<std::endl;
            display_playlist(playlist,*current_song);
        }
        else if(selection=='L'){
            current_song=playlist.end();
            current_song--;
            play_current_song(*current_song);
        }
        else if(selection=='Q'){
            std::cout<<"Quiting.....Playlist closed!"<<std::endl;
        }
    }while(selection!='Q');
    
    return 0;
}
