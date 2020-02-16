btree* tree::treecopy(btree *nwnode)
{
    stack S,S1;
    btree *temp;
    btree *temp1;
    temp = root;
    clone = new btree;
    temp1  = clone;
    temp1->left = temp1->right = NULL;
    while(1)
    {
        temp1->data = temp->data;
        if(temp->right!=NULL)
        {
            S.push(temp->right);
            temp1->right = new btree;
            temp1->right->left = temp1->right->right = NULL;
            S1.push(temp1->right);
        }
        if(temp->left!=NULL)
        {
            S.push(temp->left);
            temp1->left = new btree;
            temp1->left->left = temp1->left->right = NULL;
            S1.push(temp1->left);
        }
        if(S.isEmpty())
            break;
        temp = S.pop();
        temp1 = S1.pop();
    }
    cout<<"\nCopied Successfully";
    return clone;
}