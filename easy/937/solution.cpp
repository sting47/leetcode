class Solution {
public:
    typedef pair<string, string> Pair;
    static bool alphaCompareSt(const string &p1, const string &p2) {
        // same freq, sort with alphabatic order
        auto minPsize = p1.size() < p2.size() ? p1.size() : p2.size();
        for( auto i = 0; i < minPsize; i++ ) {
            if( p1[i] < p2[i] )
                return true;
            else if( p1[i] > p2[i] )
                return false;
            else continue;
        }
        return p1.size() < p2.size() ? true : false;
    }
    static bool alphaCompare(const Pair &p1, const Pair &p2) {
        // same freq, sort with alphabatic order
        auto minPsize = p1.second.size() < p2.second.size() ? p1.second.size() : p2.second.size();
        for( auto i = 0; i < minPsize; i++ ) {
            if( p1.second[i] < p2.second[i] )
                return true;
            else if( p1.second[i] > p2.second[i] )
                return false;
            else continue;
        }
        if( p1.second.size() != p2.second.size() )
            return p1.second.size() < p2.second.size() ? true : false;
        else {
            // use the identifier to compare
            auto p1Id = getId(p1.first);
            auto p2Id = getId(p2.first);
            return alphaCompareSt( p1Id, p2Id );
        }
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        // O(n) - process the input into 2 diff vectors
        for( auto i = 0; i < logs.size(); i++ ) {
            string data = cutIdf(logs[i]);
            if( isdigit(data[0]) ) {
                digVec.push_back( logs[i] );
            }
            else {
                letVec.push_back( Pair( logs[i], cutIdf(logs[i]) ) );
            }
        }
        
        // O(nlogn) - sort the letter log
        sort( letVec.begin(), letVec.end(), alphaCompare );
        
        // O(n) - output to out
        for( auto i = 0; i < letVec.size(); i++ )
            out.push_back( letVec[i].first );
        for( auto i = 0; i < digVec.size(); i++ )
            out.push_back( digVec[i] );
        return out;
    }
private:
    static string getId(string inp) {
        string in;
        istringstream inS(inp);
        inS >> in;
        return in;
    }
    static string cutIdf(string inp) {
        string in;
        istringstream inS(inp);
        inS >> in;
        return inp.substr( in.size() + 1, inp.size() - in.size() - 1 );
    }
    vector<Pair> letVec;
    vector<string> digVec;
    vector<string> out;
};
