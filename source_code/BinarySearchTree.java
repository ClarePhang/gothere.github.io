/* 
* @Author: Beinan
* @Date:   2015-01-08 20:52:49
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-08 22:04:33
*/

public class BinarySearchTree {
    TreeNode root = null;

    class TreeNode{
      int value;
      int position;
      TreeNode left = null, right = null;
      TreeNode(int value, int position){ 
        this.value = value; 
        this.position = position; 
      }
    }

    public void add(int value, int position){
      if(root == null){
        root = new TreeNode(value, position);
      } else {
        add(value, position, root);
      }
    }

    private void add(int value, int position, TreeNode node){
      if(node == null)
        throw new RuntimeException("treenode cannot be null");
      if(node.value == value)
        return; //ignore the duplicated value
      if(value < node.value){
        if(node.left == null){
          node.left = new TreeNode(value, position);
        }else{
          add(value, position, node.left);
        }
      }else{
        if(node.right == null){
          node.right = new TreeNode(value, position);
        }else{
          add(value, position, node.right);
        }
      }
    }

    public int search(int value){
      return search(value, root);
    }

    private int search(int value, TreeNode node){
      if(node == null)
        return -1; //not found
      else if(value < node.value){
        System.out.println("Searching left");
        return search(value, node.left);
      }
      else if(value > node.value){
        System.out.println("Searching right");
        return search(value, node.right);
      }
      else  
        return node.position;
    }

    public void travel(){
      travel(root);
    }
    public void travel(TreeNode node){
      if(node == null)
        return;
      travel(node.left);
      System.out.println(" " + node.value);
      travel(node.right);
    }
    public int depth(){
      return depth(root);
    }

    private int depth(TreeNode node){
      if(node == null)
        return 0;
      int leftDepth = depth(node.left);
      int rightDepth = depth(node.right);
      return Math.max(leftDepth, rightDepth) + 1;
    }
    public void levelOrder(){
      int depth = depth();
      for(int level = 0; level < depth; level ++){
        printLevel(root, level);
        System.out.println("\n-------------------");
      }
    }
    private void printLevel(TreeNode node, int level){
      if(node == null)
        return;
      if(level == 0){
        System.out.print(" " + node.value);
      }else{
        printLevel(node.left, level - 1);
        printLevel(node.right, level - 1);
      }
    }
    public static void main(String[] args) {
      BinarySearchTree bst = new BinarySearchTree();
      int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
      for(int i = 0; i < a.length; i++){
        bst.add(a[i], i);    
      }

      System.out.println("Tree Depth:" + bst.depth());
      bst.levelOrder();
      //bst.travel();
      //System.out.println(bst.search(8));
      //System.out.println(bst.search(3));
      //System.out.println(bst.search(6));
      //System.out.println(bst.search(30));
      
       
    }
}