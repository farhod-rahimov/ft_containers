#include <iostream>

typedef struct s {
public:
    s(int number, s *parent) : value(number), parent(parent) {
      lh = nullptr;
      rh = nullptr;
    };
    ~s(){
      delete lh;
      delete rh;
    }
    int value;
    s *parent;
    s *lh;
    s *rh;
} tree;

typedef struct ss {
    tree *t_prev;
    ss  *h_prev;
} holder;



tree *ft_create_new_el(int number, tree *parent);
holder *ft_create_new_holder(tree *prev);
void ft_insert(int number, tree * root, bool first);
tree *ft_get_start(tree *root);
tree *ft_get_end(tree *root);

tree *ft_get_start(tree *root) {
  tree *tmp;

  tmp = root;
  while (tmp->lh) {
    tmp = tmp->lh;
  }
  return (tmp);
}

tree *ft_get_end(tree *root) {
  tree *tmp;

  tmp = root;
  while (tmp->rh) {
    tmp = tmp->rh;
  }
  return (tmp);
}

void ft_insert(int number, tree * root, bool first) {
  tree *tmp = root;
  if (first) {
      root->value = number;
    return ;
  }
  while (tmp) {
    if (number < tmp->value && tmp->lh) {
      tmp = tmp->lh;
    }
    else if (number < tmp->value && !tmp->lh) {
      tmp->lh = ft_create_new_el(number, tmp);
      return ;
    }
    else if (!(number < tmp->value) && tmp->rh) {
      tmp = tmp->rh;
    }
    else {
      tmp->rh = ft_create_new_el(number, tmp);
      return ;
    }
  }
}

tree *ft_create_new_el(int number, tree *parent) {
  tree *new_tree = new tree(number, parent);

  new_tree->value = number;
  new_tree->lh = nullptr;
  new_tree->rh = nullptr;

  return (new_tree);
}

holder *ft_create_new_holder(holder *h_prev, tree *t_prev) {
  holder *new_holder = new holder;

  new_holder->t_prev = t_prev;
  new_holder->h_prev = h_prev;
  return (new_holder);
};

tree *ft_plus(tree *current) {
  tree *tmp = current;

  if (tmp->rh) {
    tmp = tmp->rh;
    while (tmp->lh) {
      tmp = tmp->lh;
    }
  }
  else {
    while (tmp->value <= current->value && tmp->parent) {
      tmp = tmp->parent;
    }
    if (tmp->value <= current->value)
      return (nullptr);
  }
  return (tmp);
}

tree *ft_minus(tree *current) {
  tree *tmp = current;

  if (tmp->lh) {
    tmp = tmp->lh;
    while (tmp->rh) {
      tmp = tmp->rh;
    }
  }
  else {
    while (tmp->value >= current->value && tmp->parent) {
      tmp = tmp->parent;
    }
    if (tmp->value >= current->value)
      return (nullptr);
  }
  return (tmp);
}

#include <cstdlib>

int main()
{

  tree *root = ft_create_new_el(0, nullptr);

  ft_insert(-1, root, 1);
  srand(0);

  for (int i = 0; i < 30; i++) {
    ft_insert(rand() % 1000, root, 0);
  }

  

  // for (tree *start = ft_get_start(root); start != nullptr; start = ft_plus(start)) {
  //   std::cout << start->value << "\n";
  // }

  for (tree *start = ft_get_end(root); start != nullptr; start = ft_minus(start)) {
    std::cout << start->value << "\n";
  }

}