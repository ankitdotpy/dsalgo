using namespace std;
struct node{
	int data;
	struct node *next;

	node(int data){
		this->data = data;
		next = nullptr;
	}
};

class LinkedList{
public:
	struct node *head = nullptr;

	void insertNode(int data){
		struct node *newNode = new node(data);
		if(!head){
			head = newNode;
			return;
		}

		struct node *temp = head;
		while(temp->next){
			temp = temp->next;
		}

		temp->next = newNode;
	}

	void insertAtPos(int data, int pos){
		struct node *newNode = new node(data);
		if(pos==0){
			newNode->next = head;
			head = newNode;
			return;
		}

		int curr = 0;
		struct node *temp1, *temp2;
		temp1 = head;
		temp2 = nullptr;
		while(temp1 and curr!=pos){
			auto p = temp1;
			temp1 = temp1->next;
			temp2 = p;
			curr++;
		}

		if(curr==pos){
			newNode->next = temp1;
			temp2->next = newNode;
		}
	}

	void printList(){
		struct node *temp = head;
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<'\n';
	}
};