class Solution {
public:
    string decodeString(string s) {
        string kString, beforeString, firstString, restString, dstString;
        // find first [ and then find the corresponding ]
        int i = 0, lcnt = 0, rcnt = 0;
        int lpos = 0, rpos = 0;
        int k = 0, lkpos = 0;
        bool lkpos_init = false;
        for( i = 0; i < s.size(); i++ ) {
            if( s[i] == '[' && lcnt == 0 ) {
                lpos = i;
                kString = s.substr( lkpos, i-lkpos );
                k = atoi( kString.c_str() );
                lcnt++;
            }
            else if( s[i] == '[' )
                lcnt++;
            else if( s[i] == ']' && lcnt == (rcnt+1) ) {
                rpos = i;
                break;
            }
            else if( s[i] == ']' )
                rcnt++;
            else if( isdigit(s[i]) && !lkpos_init ) {
                lkpos = i;
                lkpos_init = true;
            }
        }
        
        // no [] found, just return original string
        if( lcnt == 0 ) {
            return s;
        }
        
        // assign rest of string to decode
        beforeString = s.substr( 0, lpos-kString.size() );
        firstString = s.substr( lpos+1, rpos-lpos-1 );
        restString = s.substr( rpos+1, s.size()-rpos-1 );
        
        dstString.append( beforeString );
        for( i = 0; i < k; i++ ) {
            dstString.append( decodeString(firstString) );
        }
        dstString.append( decodeString(restString) );
        
        return dstString;
    }
};
