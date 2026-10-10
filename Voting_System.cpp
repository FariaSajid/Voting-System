#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Candidate{
    string name;
    int votes;
public:
    Candidate(string n) : name(n), votes(0) {}
    void addVote(){ 
		votes++; 
	}    
    int getVotes() const{ 
		return votes; 
	}    
    string getName() const{ 
		return name; 
	}
};
class VotingSystem{
    vector<Candidate> candidates;
public:
    void addCandidate(const string& name) {
        candidates.push_back(Candidate(name));
    }    
    bool castVote(const string& name){
        for(auto& c : candidates) {
            if(c.getName() == name){
                c.addVote();
                return true;
            }
        }
        return false; // candidate not found
    }
    void displayResults() const{
        cout << "\n--- Voting Results ---\n";
        for(const auto& c : candidates) {
            cout << c.getName() << ": " << c.getVotes() << " votes\n";
        }
    }
    void showWinner() const{
        int maxVotes = -1;
        vector<string> winners;
        for(const auto& c : candidates){
            if(c.getVotes() > maxVotes){
                maxVotes = c.getVotes();
                winners.clear();
                winners.push_back(c.getName());
            }else if(c.getVotes() == maxVotes){
                winners.push_back(c.getName());
            }
        }   
        if(maxVotes == 0){
            cout << "No votes cast yet.\n";
            return;
        }        
        cout << "\n--- Winner(s) ---\n";
        for (const auto& w : winners) {
            cout << w << "\n";
        }
        cout << "with " << maxVotes << " vote(s).\n";
    }
};
int main() {
    VotingSystem voting;
    int n;
    cout << "Enter number of candidates: ";
    cin >> n;
    cin.ignore(); // clear newline  
    for(int i = 0; i<n; ++i){
        string name;
        cout << "Enter candidate #" << i+1 << " name: ";
        getline(cin, name);
        voting.addCandidate(name);
    }    
    cout << "\nVoting started! Enter candidate names to vote.\n";
    cout << "Type 'exit' to stop voting.\n";
    while(true){
        cout << "Vote for: ";
        string voteName;
        getline(cin, voteName);
        if(voteName == "exit") 
			break;        
        if(voting.castVote(voteName)){
            cout << "Vote recorded.\n";
        }else{
            cout << "Candidate not found. Try again.\n";
        }
    }    
    voting.displayResults();
    voting.showWinner();    
    return 0;
}
