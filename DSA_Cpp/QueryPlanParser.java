import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class QueryPlanParser {
    private int[] spaceDP;
    public String getFile(String fileLoc) {
        File f = new File(fileLoc);
        String res="";
        try(FileReader fileReader = new FileReader(f);
        BufferedReader reader = new BufferedReader(fileReader)) {
            StringBuilder builder = new StringBuilder();
            String st;
            while ((st = reader.readLine()) != null) {
                builder.append(st + "\n");
            }
            res = builder.toString();
        } catch (Exception e){
            System.out.println("Error opening file. Please ensure file exists at "+ fileLoc);
        }

        return res;
    }
    private int getNumSpaces(String s){
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)!=' ')
                return i;
        }
        return s.length();
    }

    private TreeNode constructTree(String[] plan, int idx, int spaces){
        if(idx>=plan.length)
            return null;
        if(getNumSpaces(plan[idx]) != spaces)
            return null;
        TreeNode curr = new TreeNode(plan[idx]);
        int childSpace;
        if(idx < plan.length-1) {
            childSpace = getNumSpaces(plan[idx + 1]);
            for (int i = idx + 1; i < plan.length; i++) {
                TreeNode child = constructTree(plan, i, childSpace);
                if (child != null)
                    curr.addChild(child);
            }
        }
        return curr;
    }

    public TreeNode parsePlan(){
        String[] plan = getFile("/Users/akshitmethi/Documents/Akshit/Dev/SparkPlanAnalysis/query.txt")
                .split("\n");
        if(plan.length == 0)
            return null;
        int j=0;
        for(j=0; j< plan.length; j++){
            if(plan[j].contains("Physical Plan"))
                break;
        }
        int[] spaceDP = new int[plan.length - j+1];
        Arrays.fill(spaceDP,-1);


        return constructTree(plan,j+1,0);
    }

    public void printTree(TreeNode root,int depth){
        if(root==null)
            return;
        System.out.println(depth + "-> "+ root.getName());
        root.getChilds().stream().forEach(x->printTree(x,depth+1));
    }

    public static void main(String[] args) {
        QueryPlanParser parser = new QueryPlanParser();
        TreeNode head = parser.parsePlan();
        parser.printTree(head,0);
    }
}


class TreeNode{
    private final String name;
    private final List<TreeNode> childs;
    public TreeNode(String name){
        this.name = name;
        this.childs = new ArrayList<TreeNode>();
    }

    public String getName() {
        return name;
    }

    public List<TreeNode> getChilds() {
        return childs;
    }

    public void addChild(TreeNode node){
        this.childs.add(node);
    }
}
