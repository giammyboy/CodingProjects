class Node {
	constructor(data, next=undefined, prev=undefined) {
		this.data = data;
		this.next = next;
		this.prev = prev;
	}
}

class LinkedList {
	constructor(data) {
		this.head = new Node(data);
	}

	push(data) {
		let iter = this.head;
		let buffer = this.head;
		while (iter.next !== undefined) {
			iter = iter.next;
			iter.prev = buffer;
			buffer = iter;

		}
		iter.next = new Node(data);
		iter.next.prev = iter;
	}

	get lastNode() {
		let iterNode = this.head;
		while (iterNode.next !== undefined) {
			iterNode = iterNode.next;
		}
		return iterNode;
	}

	pop() {
		let node = this.lastNode;
		node.prev.next = undefined;
		return node.data;
	}

	count() {
		let counter = 0;
		let iterNode = this.head;
		while (iterNode !== undefined) {
			counter += 1;
			iterNode = iterNode.next;
		}
		return counter;
	}

	get elements() {
		let datas = [];
		let iterNode = this.head;
		while (iterNode !== undefined) {
			datas.push(iterNode.data);
			iterNode = iterNode.next;
		}
		return datas;
	} 

	shift() {
		let node = this.head;
		this.head = this.head.next;
		return node.data;
	}

	unshift(data) {
		let head = this.head;
		this.head = new Node(data);
		this.head.next = head;
		head.prev = this.head;
	}

	delete(value) {
		let iterNode = this.head;
		if (iterNode.data === value) {
			this.head = this.head.next;
		}
		while (iterNode.data !== value) {
			iterNode = iterNode.next;
		}
		if (iterNode.prev !== undefined) iterNode.prev.next = iterNode.next;
		if (iterNode.next !== undefined) iterNode.next.prev = iterNode.prev;
	}
}

let l = new LinkedList(1);
l.push(2);
l.push(3);
l.push(4);
l.unshift(5);
l.delete(5)
console.log(l.elements);