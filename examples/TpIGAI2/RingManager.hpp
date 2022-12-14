//
// Created by akhaten on 12/14/22.
//

#ifndef MESHMANIPULATOR_RINGMANAGER_HPP
#define MESHMANIPULATOR_RINGMANAGER_HPP

#include <set>

#include <MeshManipulator/Mesh/ObjectMesh.hpp>


class RingManager {

    public:

        RingManager(MyOpenMesh* mesh);
        ~RingManager();


        void compute(unsigned int id_vertex, int nb_ring);

        /**
         * Get ring from id
         * @param id_ring : id of ring
         * @return set of vertex in rings
         * @warning id_ring = 0 to get the vertex of reference.
         * So, there is only one vertex in 0-ring
         */
        std::set<unsigned int> get(unsigned int id_ring);

    private:

        MyOpenMesh* mesh;
        unsigned int id_vertex;
        unsigned int nb_ring;

        std::vector<std::set<unsigned int>> vertices_rings;

        void clear();
        std::set<unsigned int> ring_from_vertices(std::set<unsigned int> ids_vertices);





};


#endif //MESHMANIPULATOR_RINGMANAGER_H
