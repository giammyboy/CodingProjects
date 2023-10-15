import random


class Card:

    RANKS = {
                            1: "Ace",
                            2: "2",
                            3: "3", 
                            4: "4",
                            5: "5", 
                            6: "6", 
                            7: "7", 
                            8: "8",
                            9: "9", 
                            10: "10", 
                            11: "Jack", 
                            12: "Queen", 
                            13: "King"
                            }
    SUITS = {
                            0: "Hearts", 
                            1: "Diamonds", 
                            2: "Clubs", 
                            3: "Spades"
                            }

    def __init__(self, rank: int, suit: int):
        self.rank = rank
        self.suit = suit

    def __str__(self):
        return f"{Card.RANKS[self.rank]} of {Card.SUITS[self.suit]}"


class ListOfCard:

    def __init__(self, n_cards: int = 0):
        self.n_cards = n_cards
        self.list = []
        self.built = False

    def __str__(self):
        return '\n'.join(str(element) for element in self.list)

    def build(self):
        for suit in Card.SUITS.keys():
            for rank in Card.RANKS.keys():
                self.add(Card(rank, suit))
        self.built = True

    def add(self, card: Card):
        self.list.append(card)

    def remove(self, card: Card):
        self.list.remove(card)

    def draw(self):
        return self.list.pop()


class Deck(ListOfCard):

    def __init__(self, n_cards: int = 52, **settings):
        super().__init__(n_cards)
        if "build" not in settings or settings["build"] == True:
            self.build()
        else:
            return
        if "type" in settings:
            if settings["type"] == "no8-9-10":
                for card in self.list:
                    if card.rank == 9:
                        self.list.remove(card)
                    elif card.rank == 8: 
                        self.list.remove(card)
                    elif card.rank == 10:
                        self.list.remove(card)

        if 'shuffle' in settings:
            if settings["shuffle"] == True:
                random.shuffle(self.list)
            else:
                pass

        
class Hand(ListOfCard):

    def __init__(self, n_cards: int = 3):
        super().__init__(n_cards)

class Player:

    n_player = 1

    def __init__(self) -> None:
        self.name = f"Player {Player.n_player}"
        self.hand = Hand()
        Player.n_player += 1

class Game:

    def __init__(self, n_players: int = 2) -> None:
        self.players = [Player() for _ in range(n_players)]
        self.deck = Deck()
    


d = Deck(shuffle = False, type = "no8-9-10")
print(d)

