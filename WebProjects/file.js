class Card {
    constructor(rank='Ace', suit='Hearts') {

        this.rank = this.RANKS[rank];
        this.suit = suit;
    }

    RANKS = {
        'Ace': {
            number: '1',
            value: 11,
        },
        '2': {
            number: '2',
            value: 0,
        },
        '3': {
            number: '3',
            value: 10,
        },
        '4': {
            number: '4',
            value: 0,
        },
        '5': {
            number: '5',
            value: 0,
        },
        '6': {
            number: '6',
            value: 0,
        },
        '7': {
            number: '7',
            value: 0,
        },
        'Jack': {
            number: '11',
            value: 2,
        },
        'Queen': {
            number: '12',
            value: 3,
        },
        'King': {
            number: '13',
            value: 4,
        },
    };

    SUITS = {
        'Heart': {
            power: 0,
            isSuitComanding: false,
        },
        'Diamonds': {
            power: 0,
            isSuitComanding: false,
        },
        'Heart': {
            power: 0,
            isSuitComanding: false,
        },
        'Heart': {
            power: 0,
            isSuitComanding: false,
        },
        
    }
}

c = new Card(0, 0);
console.log(c);