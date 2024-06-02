/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:20:00 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/26 21:09:40 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv) {
    t_stack_node *root = NULL;
    t_stack_node *current = NULL;
    char **split;
    int i = 0;
    int value;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 1;
    split = ft_split(argv[1], ' ');
    while (split[i] != NULL) {
        if (error_nondigit(split[i])) {
            fprintf(stderr, "Error: Non-digit input detected\n");
            free_array(split);  // Assuming free_array properly frees a char** array
            free_stack(&root);
            return 1;
        }
        value = atoi(split[i]);
        t_stack_node *temp = create_node(value);
        if (!root) {
            root = temp;
        } else {
            current->fwd = temp;
            temp->bwd = current;
        }
        current = temp;
        i++;
    }
    free_array(split);  // Clean up the split array

    dll_bubble_sort(&root);
    printf("Sorted values: ");
    current = root;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->fwd;
    }
    printf("\n");
    free_stack(&root);
    return 0;
}

void free_array(char **array) {
    if (array == NULL) return;
    int i = 0;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}