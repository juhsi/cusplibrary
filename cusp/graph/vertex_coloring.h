/*
 *  Copyright 2008-2014 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file vertex_coloring.h
 *  \brief Breadth-first traversal of a graph
 */

#pragma once

#include <cusp/detail/config.h>

#include <thrust/execution_policy.h>

namespace cusp
{
namespace graph
{
/*! \addtogroup algorithms Algorithms
 *  \addtogroup graph_algorithms Graph Algorithms
 *  \brief Algorithms for processing graphs represented in CSR and COO formats
 *  \ingroup algorithms
 *  \{
 */

/*! \cond */
template <typename DerivedPolicy,
          typename MatrixType,
          typename ArrayType>
size_t vertex_coloring(const thrust::detail::execution_policy_base<DerivedPolicy>& exec,
                       const MatrixType& G,
                       ArrayType& colors);
/*! \endcond */

/**
 * \brief Performs a Breadth-first traversal of a graph starting from a given source vertex.
 *
 * \tparam MARK_PREDECESSORS Boolean value indicating whether to return level sets, \c false, or
 * predecessor, \c true, markers
 * \tparam MatrixType Type of input matrix
 * \tparam ArrayType Type of labels array
 *
 * \param G A symmetric matrix that represents the graph
 * \param src The source vertex to begin the BFS traversal
 * \param labels If MARK_PREDECESSORS is \c false then labels will contain the
 * level set of all the vertices starting from the source vertex otherwise
 * labels will contain the immediate ancestor of each vertex forming a ancestor
 * tree.
 *
 *  \see http://en.wikipedia.org/wiki/Breadth-first_search
 *
 *  \par Example
 *
 *  \code
 *  #include <cusp/csr_matrix.h>
 *  #include <cusp/print.h>
 *  #include <cusp/gallery/grid.h>
 *
 *  //include bfs header file
 *  #include <cusp/graph/vertex_coloring.h>
 *
 *  int main()
 *  {
 *     // Build a 2D grid on the device
 *     cusp::csr_matrix<int,float,cusp::device_memory> G;
 *     cusp::gallery::grid2d(G, 4, 4);
 *
 *     cusp::array1d<int,cusp::device_memory> labels(G.num_rows);
 *
 *     // Execute a BFS traversal on the device
 *     cusp::graph::vertex_coloring(G, 0, labels);
 *
 *     // Print the level set constructed from the source vertex
 *     cusp::print(labels);
 *
 *     return 0;
 *  }
 *  \endcode
 */
template<typename MatrixType, typename ArrayType>
size_t vertex_coloring(const MatrixType& G,
                       ArrayType& colors);
/*! \}
 */

} // end namespace graph
} // end namespace cusp

#include <cusp/graph/detail/vertex_coloring.inl>
