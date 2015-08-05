#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>

void readHand ( vector < pair<char,char> > &white, vector < pair<char,char> &black,string str) 
{
    isstream iss(str);
    char chr;
    int i=0;
    while ( i<30 )
    {
        if (i<15)
            white.push_back(make_pair(str[i],str[i+1]));
        else
            black.push_back(make_pair(str[i],str[i+1]));
        i+=3;
    }
}

int clubSameValues( vector< pair<int,char> > 

int straightFlush( vector< pair<char,char> > &hand)
{
    int value=hand[0].first;
    char suit=hand[0].second;
    forall(i,1,5)
    {
        if (hand[i].first!=value+1 && hand[i].second!=suit)
            return make_pair(0,0);
        else 
            value++;
    }
    
    return make_pair(10,hand[4].first);
}

int straight( vector< pair<int,char> > &hand)
{
    int value =  hand.first;
    forall(i,1,5)
    {
        if (hand[i].first!=value+1)
            return make_pair(0,0);
        else
            value++;   
    }
    return make_pair(6,hand[4].first)
}

int flush( vector< pair<int,char> > &hand)
{
    char suit =  hand[0].second;
    forall(i,1,5)
    {
        if (hand[i].second!=suit)
            return make_pair(0,0);
        else
            value++;   
    }
    return make_pair(7,highcardvalue(hand))
}

int fourOfAKind( vector< pair<int,char> > &hand)
{
    if (hand[1].first==hand[2].first && hand[2].first==hand[3].first )
    {
        if (hand[0].first==hand[1].first)
            return make_pair(6,hand[4].first)
        else if (hand[3].first==hand[4].first)
            return make_pair(6,hand[0].first)
        else
            return make_pair(0,0);
    }
    else
        return make_pair(0,0);
}

int fullHouse

int rank(vector< pair<char,char> > &hand)
{
    sort(hand.begin(),hand.end());
    clubSameValues(hand);
    if (straightFlush(hand))
        return straightFlush(hand);
    else if (straight(hand))
        return straight(hand);
    else if (flush(hand))
        return flush(hand);
    else if (fourOfAKind(hand))
        return fourOfAKind(hand);
    else if (fullHouse(hand))
        return fullHouse(hand);
    else if (threeOfAKind(hand))
        return threeOfAKind(hand);
    else if (twoPairs(hand))
        return twoPairs(hand);
    else if (pair(hand))
        return pair(hand);
    else if (highCard(hand))
        return highCaard(hand);
    else 
        return 0;
}
        
            
    
    

int main()
{
    vector< pair<char,char> > white,black;
    string str;
    while (true)
    {
        getline(cin,str);
        if (str.empty())
            break;
        readHand(str,white,black);
        int whiteRank=rank(white);
        int blackRank=rank(black);
        if (whiteRank > blackRank)
            cout<<"Black wins.\n";
        else if (whiteRank < blackRank)
            cout<<"White wins.\n";
        else 
            cout<<"Tie.\n";
    }
    return 0;
}
        
    
    
    
    
    
    
    