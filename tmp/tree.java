import java.util.ArrayList;
public class tree{
    public static class Node{
        int data = 0;
        Node left = null;
        Node right = null;
        Node(int data){
            this.data = data;
        }
    }
    static int idx = 0;
    public static Node constructTree(int [] arr){
        if(idx == arr.length || arr[idx] == -1 ){
            idx++;
            return null;
        }
        Node node = new Node(arr[idx++]);
        node.left = constructTree(arr);
        node.right = constructTree(arr);
        return node;
    }
    public static void display(Node node){
        if(node == null)    return;
        StringBuilder sb = new StringBuilder();
        sb.append(node.left == null ? "." : node.left.data);
        sb.append(" <- " + node.data + " -> ");
        sb.append(node.right == null ? "." : node.right.data);
        System.out.println(sb);

        display(node.left);
        display(node.right);
    }

    public static boolean find(Node root, int ele){
        if(root == null)    return false;
        if(root.data == ele)    return true;
        return find(root.left,ele) || find(root.right,ele);
    }
    public static boolean rootToNode(Node root, int ele, ArrayList<Node> arr){
        if(root == null)    return false;
        if(root.data == ele)    {
            arr.add(root);
            return true;
        }
        boolean res = rootToNode(root.left,ele,arr) || rootToNode(root.right,ele,arr);
        if(res){
            arr.add(root);
        }
        return res;
    }

    public static void solve(){
        int[] arr = {10,20,40,-1,-1,50,80,-1,-1,90,-1,-1,30,60,100,-1,-1,-1,70,110,-1,-1,120,-1,-1}; 
        Node root = constructTree(arr);
        // display(root);
        ArrayList<Node> fw = new ArrayList<>();
        System.out.println(rootToNode(root, 30, fw));
        for(Node ele : fw)  System.out.print(ele.data+" ");

    }

    public static void main(String[]args){
        solve();
    }
}
