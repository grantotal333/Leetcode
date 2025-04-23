#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
public:
    unordered_map<int, unordered_set<int>> usuarios;   // cada usuario -> seguidos
    unordered_map<int, vector<int>> posts;             // cada usuario -> tweets

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        usuarios[userId].insert(userId); // Asegura que este en la seccion de usuario
        posts[userId].push_back(tweetId); // Asegura que este tenga su post en la seccion de posts
    }

    vector<int> getNewsFeed(int userId) {
        unordered_set<int> vistos; // Para evitar duplicados
        vector<int> feed;

        if (usuarios.count(userId)) { // Si el usuario existe
            for (int seguido : usuarios[userId]) { // Para cada seguido
                if (posts.count(seguido)) { // Si el seguido tiene posts
                    for (int tweet : posts[seguido]) { // Para cada tweet del seguido
                        if (!vistos.count(tweet)) { // Si no lo ha visto
                            feed.insert(feed.begin(), tweet); // Insertar al inicio para mantener el orden
                            vistos.insert(tweet); // Marcar como visto
                        }
                    }
                }
            }
        }

        if (feed.empty()) { // Si no hay tweets
            return {}; // Retornar un vector vacio
        }

        return feed; // Retornar el feed con los tweets del usuario y sus seguidos
    }

    void follow(int followerId, int followeeId) { 
        if (followerId != followeeId) { // No puede seguirse a si mismo
            usuarios[followerId].insert(followeeId); // Agregar al seguido
        }
    }

    void unfollow(int followerId, int followeeId) { 
        if (followerId != followeeId) { // No puede dejar de seguirse a si mismo
            usuarios[followerId].erase(followeeId); // Eliminar al seguido
        }
    }
};

int main() { // esta parte solo es comprovación de que el código funciona gracias :)
    Twitter tw;

    tw.postTweet(1, 1);
    vector<int> feed1 = tw.getNewsFeed(1);
    cout << "Feed 1: ";
    for (int t : feed1) cout << t << " ";
    cout << endl;

    tw.follow(2, 1);
    vector<int> feed2 = tw.getNewsFeed(2);
    cout << "Feed 2: ";
    for (int t : feed2) cout << t << " ";
    cout << endl;

    tw.unfollow(2, 1);
    vector<int> feed3 = tw.getNewsFeed(2);
    cout << "Feed 3: ";
    for (int t : feed3) cout << t << " ";
    cout << endl;










/*
    tw.postTweet(2, 6);
    vector<int> feed2 = tw.getNewsFeed(1);
    cout << "Feed 2: ";
    for (int t : feed2) cout << t << " ";
    cout << endl;

    tw.unfollow(1, 2);
    vector<int> feed3 = tw.getNewsFeed(1);
    cout << "Feed 3: ";
    for (int t : feed3) cout << t << " ";
    cout << endl;
*/


    return 0;
}