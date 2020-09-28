public class linkedlistClass{
    public static class linkedlist{
        protected class Node{
            int data  = 0;
            Node next = null;
            Node(int data){
                this.data = data;
            }
        }

        private int elementCount = 0;
        private Node head = 0;
        private Node tail = 0;

        //Basic Functions

        public int size(){
            return elementCount;
        }

        public boolean isEmpty(){
            return this.elementCount == 0;
        }

        private Node getNodeAt(int idx){

        }

    }

    //add ============================================================
    protected void addFirstNode(Node node){
        if(this.head == null){
            this.head = node;
            this.tail = node;
        }
        else{
            node.next
        }
    }
    public void addFirst(int val){
        Node node = new Node(val);
        addFirstNode(node);
    }

    public void addLast(){
        
    }



    //get ============================================================
    protected Node getFirstNode(){
        return this.head;
    }
    public int getFirst()throws Exception{
        if(this.elementCount == 0) {
            throw new Exception("NullPointerException: Aman");
        }
        Node node = getFirstNode();
        return node.data;
    }

    protected Node getLastNode(){
        return this.tail;
    }
    public int getLast()throws Exception{
        if(this.elementCount == 0) {
            throw new Exception("NullPointerException: Aman");
        }
        Node node = getLastNode();
        return node.data;
    }

    public static void main(String[] args){
        linkedlist ll = new linkedlist();

    }
}