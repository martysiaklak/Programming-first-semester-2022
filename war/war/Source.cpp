//вектор пар карт. масть ≥ ранг
//вже готовий список
//шоб не повторювалис€ б≥льш н≥ж 4 картки

//клас гейм. заповненн€ стеку. 
//
//
//
#include <iostream>
#include <stack>
#include <map>
using namespace std;

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Value { ACE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card 
{
private:
    Suit suit;
    Value value;
public:
    Card(Suit suit, Value value) : suit(suit), value(value) {}

    bool compare(const Card& other) const 
    {
        if (this->value == other.value) 
        {
            return this->suit > other.suit;
        }
        return this->value > other.value;
    }
};
class CardsOperations
{
private:
    stack<Card> cards;
public:
    void fillStackRandomly() {
    }
   
    void addCardsToBottom(const Card& enemyCard, const Card& playerCard) {
        cards.push(enemyCard);
        cards.push(playerCard);
    }
};


//enum Rank
//{
//    Ace,
//    Six,
//    Seven,
//    Eight,
//    Nine,
//    Ten,
//    Jack,
//    Queen,
//    King
//};
//
//
// ‘ункц≥€, €ка повертаЇ р€док, що в≥дпов≥даЇ рангу карти
//string rankToString(Rank rank)
//{
//    switch (rank) {
//    case Ace:
//        return "Ace";
//    case Six:
//        return "6";
//    case Seven:
//        return "7";
//    case Eight:
//        return "8";
//    case Nine:
//        return "9";
//    case Ten:
//        return "10";
//    case Jack:
//        return "Jack";
//    case Queen:
//        return "Queen";
//    case King:
//        return "King";
//    default:
//        return "";
//    }
//}

//int main()
//{
//    // ≤н≥ц≥ал≥зуЇмо генератор випадкових чисел
//    srand(time(0));
//
//    stack<Rank> stack1;
//    stack<Rank> stack2;
//
//    int num_cards = 18;
//    map<Rank, int> used_cards;
//    for (int i = 0; i < num_cards; i++)
//    {
//        // √енеруЇмо рандомн≥ значенн€ дл€ ранг≥в та мастей карт
//        Rank rank1 = static_cast<Rank>(rand() % 9);
//        Rank rank2 = static_cast<Rank>(rand() % 9);
//        stack1.push(rank1);
//        stack2.push(rank2);
//        // ѕерев≥р€Їмо, чи не була ц€ карта використана 4 рази
//        if (used_cards[rank1] < 4)
//        {
//            stack1.push(rank1);
//            used_cards[rank1]++;
//        }
//
//        if (used_cards[rank2] < 4)
//        {
//            stack2.push(rank2);
//            used_cards[rank2]++;
//        }
//    }
//
//    cout << "Cards in the first stack:" << endl;
//    while (!stack1.empty())
//    {
//        cout << rankToString(stack1.top()) << endl;
//
//        stack1.pop();
//    }
//
//    cout << endl;
//
//    cout << "Cards in the second stack:" << endl;
//    while (!stack2.empty())
//    {
//        cout << rankToString(stack2.top()) << endl;
//
//        stack2.pop();
//    }
//
//}
