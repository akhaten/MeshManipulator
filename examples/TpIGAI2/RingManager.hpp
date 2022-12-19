//
// Created by akhaten on 12/14/22.
//

#ifndef MESHMANIPULATOR_RINGMANAGER_HPP
#define MESHMANIPULATOR_RINGMANAGER_HPP

#include <set>

#include <MeshManipulator/Mesh/ObjectMesh.hpp>
#include <OpenMesh/Core/Utils/PropertyManager.hh>


class RingManager {

    public:

        RingManager(ObjectMesh* obj_mesh);
        ~RingManager();


        /**
         * Get ring from id
         * @param id_ring : id of ring
         * @return set of vertex in rings
         * @warning id_ring = 0 to get the vertex of reference.
         * So, there is only one vertex in 0-ring
         */

        // Vertex handle storage
        std::vector<ObjectMesh::VertexHandle> vertex_handles;
        // Taken ?
        OpenMesh::VProp<bool> taken;
        // Association between no_ring and vertex handle
        OpenMesh::VProp<unsigned int> no_ring;
        // Association between valence and vertex handle
        OpenMesh::VProp<unsigned int> valence;
        // Association between opposite angle and half edge
        OpenMesh::HProp<float> angle;
        // Deformations
        OpenMesh::VProp<ObjectMesh::Point> deformation;

        void deformation_laplacian_valence(
            unsigned int id_vertex,
            unsigned int nb_rings,
            ObjectMesh::Point translation
        );

        void deformation_laplacian_angle(
            unsigned int id_vertex,
            unsigned int nb_rings,
            ObjectMesh::Point translation,
            float alpha
        );

        void deformation_function(
            unsigned int id_vertex,
            unsigned int nb_rings,
            ObjectMesh::Point translation
        );

        void update();

    private:

        ObjectMesh* obj_mesh;
        unsigned int nb_ring;

        std::vector<std::set<unsigned int>> vertices_rings;

        void clear();

        void compute(unsigned int id_vertex, unsigned int nb_ring);

        std::set<ObjectMesh::VertexHandle> ring_from_vertices(
            std::set<ObjectMesh::VertexHandle> vertices_h
        );


};


#endif //MESHMANIPULATOR_RINGMANAGER_H
