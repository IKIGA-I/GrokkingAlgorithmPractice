#include <iostream> //Input and output functionalities such as cout and endl
#include <unordered_map> //Allows use of hash table based associative container (key-value) pairs
#include <string> //allows use of std:: string for handling text data
#include <vector> //provides a dynamic array like container std::vector
#include <queue> //FIFO queue
#include <unordered_set> //hash-table based container for unique elements 

//simplifies the use of cout and endl to be used without std:: prefix
using std::cout; 
using std::endl;

//checks if a person is a mango seller if their name ends with m
//std::string ensures name is passed a const to prevent modification inside
bool is_seller(const std::string& name) { 
    return name.back() == 'm'; //accesses the last character of the string
}

template <typename T> //Makes the function generic, allowing it to work with any type T
bool search(const T& name, const std::unordered_map<T, std::vector<T>>& graph) { 
    std::queue<T> search_queue; //queue to store people whose friends need to be checked 
    std::unordered_set<T> searched; //A set to track people already searched, preventing redundant checks

    //add all friends to search queue
    // graph.find(name) accesses the list of friends (value) associated with the key name
    // -> accesses the value(list of friends) associated with the key 'name'
    //for (auto&& friend_name : ....) iterates over the list of friends
    for (auto&& friend_name : graph.find(name) -> second)
        search_queue.push(friend_name);

    //Keeps searching as long as there people left to check
    while(!search_queue.empty()) {
        T& person = search_queue.front();
        search_queue.pop();

        //only search this person if you haven't already searched them
        if(searched.find(person) == searched.end()) {
            if(is_seller(person)) {
                cout << person << " is a mango seller!" <<endl;
                return true;
            }

            //add all friends of a person to search queue
            for(auto&& friend_name : graph.find(person) -> second)
                search_queue.push(friend_name);

            //mark this person as searched
            searched.insert(person);
        }
    }

    return false;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph.insert({"you", {"alice", "bob", "claire"}});
    graph.insert({"bob", {"anuj", "peggy"}});
    graph.insert({"alice", {"peggy"}});
    graph.insert({"claire", {"thom", "jonny"}});
    graph.insert({"anuj", {}});
    graph.insert({"peggy", {}});
    graph.insert({"thom", {}});
    graph.insert({"jonny", {}});

    std::string name = "you";
    bool result = search(name, graph);
    cout << "Found mango seller: " << result << endl;
}