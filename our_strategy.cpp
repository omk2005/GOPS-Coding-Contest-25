int playCard(int a[14], int b[14], int flippedCard, int currentPot)
{
    vector<int> myCards, oppCards;
    for (int i = 1; i <= 13; i++)
    {
        if (a[i] != 0)
            myCards.push_back(i);
        if (b[i] != 0)
            oppCards.push_back(i);
    }
    if (myCards.empty())
        return -1;

    // Small pot: play lowest card - it ain't worth much
    if (currentPot <= 1)
    { 
        int cardToPlay = myCards.front();  //we pick the smallest card we have
        return cardToPlay; 
    }

    // Compute crunch value
    int remainingRounds = myCards.size(); //count how many cards we have left, which tells us how many more turns
    int crunchValue = max(15 - remainingRounds, 5);
    //15 is a starting point we chose to set a high bar for “must-win” pots early in the game.

    // Crunch time: play highest card if we can win, check if the pot is big enough 
    if (currentPot >= crunchValue && myCards.back() > oppCards.back())
    {     //our biggest card is bigger than the opponent’s biggest card.
        int cardToPlay = myCards.back(); 
        return cardToPlay;
    }

    //Estimate opponent’s play
    //scaling factor makes us play higher cards more often
    //allowing us to compete better for medium and large pots
    double p = min((static_cast<double>(currentPot) / 13.0) * 110.0, 100.0);
    int k = oppCards.size();
        //count how many cards the opponent has left and store it in k
    int i = static_cast<int>(floor((p/100.0) * (k-1)));
    //pick a card from the opponent’s list (oppCards)
    int target = (i < k) ? oppCards[i] : oppCards.back();
    // We pick the opponent’s card at that spot as our target
    // if our spot number is too big, we use their biggest card instead.

    //Play smallest card > target
    auto it = std::upper_bound(myCards.begin(), myCards.end(), target);
    if (it != myCards.end())
    {
        //smallest one we have that can beat the opponent’s card, and store it in cardToPlay.
        int cardToPlay = *it;
        return cardToPlay;
    }
    else
    { 
        if (p >= 50) //We check if the pot is pretty big (the percentage is 50 or more) worth to tie
        {
            int cardToPlay = myCards.back();
            return cardToPlay;
        }
        else //if the pot isn’t that big, we don’t want to waste a good card
        {
            int cardToPlay = myCards.front();
            return cardToPlay;
        }
    }
} 
