class Table {
    constructor(nuberOfColumns=3, numberOfRows=2) {
        this.nuberOfColumns = nuberOfColumns;
        this.numberOfRows = numberOfRows;
        this.table = (this.nuberOfColumns, this.numberOfRows) => {
            let prototype = [];
            for (let i = 0; i <= this.numberOfColumns * this.nuberOfColumns; i++) {
                prototype.push('*')
            }
            return prototype;
        }
    }

    show () {
        let string = '';
        for (let element in this.table) {
            console.log(element);
        }
    }
    }


let a = new Table();
console.log(a.table());
