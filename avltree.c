#include <stdio.h>
#include <malloc.h>

typedef char DATA; /* this could be for any record */
void printdata(DATA );

typedef struct node { /* structure of AVL tree node */
        DATA d;
        int level; /* -1 indicates a null tree, level stores max
                     no. of occupied levels below current node */
        struct node *left;
        struct node *right;
} NODE;

typedef NODE* TOP; /* enables easier pointers to pointers */

int set_level(TOP t){ /* sets level in t based on levels in subtrees */
        int left_lev=-1, right_lev=-1;
        if(t->left)
                left_lev=t->left->level;
        if(t->right)
                right_lev=t->right->level;
        /* set level to highest of left or right level + 1 */
        if(left_lev>=right_lev)
                t->level=left_lev+1;
        else
                t->level=right_lev+1;
        return t->level;
}

/*AVL tree rotation, type 1 */
void rot1(TOP *t){
        NODE *k1,*k2=*t,*x,*y,*z;
        /* assign pointers to rotation object k1,
         * and subtrees x,y and z*/
        k1=k2->left;
        x=k1->left;
        y=k1->right;
        z=k2->right;
        /* perform rotation */
        k1->right=k2;
        k2->left=y;
        /* adjust k1 and k2 levels */
        set_level(k2);
        set_level(k1);
        /* replace t parameter in caller to reflect new subtree top */
        *t=k1;
}

/*AVL rotation, type 2 */
void rot2(TOP *t){
        NODE *k1,*k2,*k3=*t,*b,*c;
        /* assign pointers to rotation object k1,
         * and subtrees b and c */
        k1=k3->left;
        k2=k1->right;
        b=k2->left;
        c=k2->right;
        /* perform rotation */
        k1->right=b;
        k3->left=c;
        k2->left=k1;
        k2->right=k3;
        /* adjust k1,k3 and k2 levels */
        set_level(k1);
        set_level(k3);
        set_level(k2);
        /* replace t parameter in caller to reflect new subtree top */
        *t=k2;
}

/*AVL rotation, type 3 */
void rot3(TOP *t){
        NODE *k1=*t,*k2,*k3,*b,*c;
        /* assign pointers to rotation object k1,
         * and subtrees b and c */
        k3=k1->right;
        k2=k3->left;
        b=k2->left;
        c=k2->right;
        /* perform rotation */
        k1->right=b;
        k3->left=c;
        k2->left=k1;
        k2->right=k3;
        /* adjust k1,k3 and k2 levels */
        set_level(k1);
        set_level(k3);
        set_level(k2);
        /* replace t parameter in caller to reflect new subtree top */
        *t=k2;
}

/*AVL rotation, type 4 */
void rot4(TOP *t){
        NODE *k1=*t,*k2,*x,*y,*z;
        /* assign pointers to rotation object k1,
         * and subtrees x,y and z*/
        k2=k1->right;
        x=k1->left;
        y=k2->left;
        z=k2->right;
        /* perform rotation */
        k1->right=y;
        k2->left=k1;
        /* adjust k1 and k2 levels */
        set_level(k1);
        set_level(k2);
        /* replace t parameter in caller to reflect new subtree top */
        *t=k2;
}

int cmp(DATA d1, DATA d2){ /* compares d1, d2 returns -1, 0 or 1 */
        if(d1<d2)
                return -1;
        else if(d1>d2)
                return 1;
        else
                return 0;
}

int avl_type(DATA di,DATA parent,DATA child){
        /* returns int 1 - 4 to indicate AVL rotation
         * type based on class of insertion.
         *
         * Parameters:  di data inserted
         *              parent data at parent
         *              child data at child
         * Returns:     1 insertion on left tree of left child
         *              2 insertion on right subtree of left child
         *              3 insertion on left subtree of right child
         *              4 insertion on right subtree of right child
         *              0 if di == child, i.e. child is leaf node
         */
        if(cmp(di,parent)<0){ /* insert on left */
                if(cmp(di,child)<0) /* ins on left ST of left */
                        return 1;
                else if(cmp(di,child) == 0) /* child is leaf */
                        return 0;
                else /* ins on right ST of left */
                        return 2;
        } else {
                if(cmp(di,child)>0) /* ins on right ST of right */
                        return 4;
                else if(cmp(di,child) == 0) /* child is leaf */
                        return 0;
                else /* ins on left ST of right */
                        return 3;
        }
}

void avlrotate(int avlrot,TOP *t){
  /* performs avlrotation based on avlrot type 1 - 4 */
        if(avlrot==1)
                rot1(t);
        else if(avlrot==2)
                rot2(t);
        else if(avlrot==3)
                rot3(t);
        else if(avlrot==4)
                rot4(t);
        else
                printf("avlrotate: illegal rotation\n");
}


int insert(DATA di,TOP *t){ /* recursively inserts di into tree
      with TOP t, returns depth of tree t after insertion */
        NODE *ins,*top=*t;
        int left_lev=-1,right_lev=-1,diff,avlrot;

        if(!top){  /* empty tree, create new tree */
                /* make node */
                ins=(NODE*)malloc(sizeof(NODE));
                ins->d=di;
                ins->level=0;
                ins->left=NULL;
                ins->right=NULL;
                *t=ins;
                return 0;
        }
        if(top->left)
                left_lev=top->left->level;
        if(top->right)
                right_lev=top->right->level;


        if(cmp(di,top->d)<0){ /* insert on left */
                if((left_lev=insert(di,&(top->left))) == -1)
                        return -1; /* report insert failure */
                avlrot=avl_type(di,top->d,top->left->d);
        } else if(cmp(di,top->d)>0){ /* insert on right */
                if((right_lev=insert(di,&(top->right))) == -1)
                        return -1; /* report insert failure */
                avlrot=avl_type(di,top->d,top->right->d);
        } else { /* duplicate key */
                printdata(di);
                printf("insert: duplicate key error\n");
                return -1;
        }
        /* check if AVL rebalance required (i.e. difference in
         * left and right subtree heights >= 2 */
        diff=left_lev - right_lev;
        if(diff >= 2 || diff <= -2){
                printf("AVL imbalance : %d AVL type: %d\n",diff,avlrot);
                /* correct imbalance by performing AVL rotation */
                avlrotate(avlrot,t);
                top=*t;
        }
        /* set and return level of current node */
        return set_level(top);
}

#define DEBUG 1 /* or 0 for less noisy output */

void printall(TOP t){ /* recursively prints data in left top right order */
        static int recsop=0; /* no of recs printed */
        if(!t){
                printf("printall: can't print NULL tree\n");
                return;
        }
        /* print left subtree */
        if(t->left)
                printall(t->left);
        /* print data for current node */
        if(DEBUG && t->left) printdata(t->left->d); else printf("  ");
        printdata(t->d);
        printf("%d ",t->level);
        recsop++;
        if(DEBUG && t->right) printdata(t->right->d); else printf("  ");
        if(recsop%4==0) printf("\n"); else printf("    ");
        /* print right subtree */
        if(t->right)
                printall(t->right);
}

void printdata(DATA d){ /* prints DATA item d */
        printf("%c ",d);
}

int main(void){ /* test code for AVL binary tree construction */
        int arr[]={80,40,50,90,100,95,20,10,45,60};
        int i;
        TOP t=NULL;
        for(i=0; i<10; i++)
                        insert(arr[i], &t);
        printall(t);
        printf("\n");
        return 0;
}
