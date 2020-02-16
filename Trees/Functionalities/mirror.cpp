void bst::mirror_image()
{
    stack S;
    node *tmp;
    node *cur;
    cur = mirror; 
    while(1)
    {
        while(cur!=NULL)
        {
            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            S.push(cur);
            cur = cur->left;
        }
        if(S.isEmpty())
            break;
        cur = S.pop();
        cur = cur->right;
    }
}