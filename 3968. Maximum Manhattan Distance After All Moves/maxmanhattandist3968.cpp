/*
At Any Point: dist=|x|+|y|
Each Move Affects Either x or y By +1 Or -1
Then, x=|l-r| And y=|u-d|

Also, In The Manhattan Meteric, The Order Of Moves Don't Affect The End Point
But Thier Magnitude Do.

Opposing Moves-> Decrease dist By 1
Similar Moves-> Increase dist By 2

Unlike Using A Stack To Cancel Out Opposing Moves, We Can: 2*(min(l,r)+min(u,d))
Also, Upto A Certain dist Accumulated, The Upcoming dist Can Never Exceed It.

*/

class Solution {
public:
    int maxDistance(string moves) {
        int r=0,l=0,u=0,d=0,usc=0; //Possible Moves Corresponding To U,D,L,R
        int mov=0; //Maximum Distance After All Moves
        for(char i:moves){
            if(i=='R') r++;
            else if(i=='L') l++;
            else if(i=='U') u++;
            else if (i=='D') d++;
            else usc++;
        }
        mov=abs(r-l)+abs(u-d)+usc;
        return mov;
    }
};
