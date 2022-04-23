    In Lab 11 you will read a graph from file into a two dimensional array.
    Then you will determine whether there is a connection between two given
    nodes of that array. Here are the details.

    The graph is stored in a file with the following format:
    Word #1: an unsigned integer representing the number of nodes in the array (n_edges)
    Word #2: an unsigned integer representing the connection strength (edge) between
        source Node 0 and target Node 0
    Word #3: an unsigned integer representing the connection strength (edge) between
        source Node 0 and target Node 1
                .
                .
                .
    Word # : an unsigned integer representing the connection strength (edge) between
        source Node 0 and target Node n_edges
    
    Word # : an unsigned integer representing the connection strength (edge) between
        source Node 1 and target Node 0
                .
                .
                .
    Word # : an unsigned integer representing the connection strength (edge) between
        source Node n_edges and target Node n_edges

    All told, there will be 1 + n_edges * n_edges unsigned integers in the file

    Read these numbers into a two dimensional array

    Then take two inputs, source and target, and determine whether or not the
    graph shows any connection between these two nodes

    The name of the data file and the values of the source and target nodes are passed as command
    line inputs. Your code should fail gracefully if the user specifies a node that does
    not exist.

    usage:
    > ./lab_11 filename source_node target_node
    > There is / is not a connection

