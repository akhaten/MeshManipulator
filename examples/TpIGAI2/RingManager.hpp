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


        void compute(unsigned int id_vertex, unsigned int nb_ring);

        /**
         * Get ring from id
         * @param id_ring : id of ring
         * @return set of vertex in rings
         * @warning id_ring = 0 to get the vertex of reference.
         * So, there is only one vertex in 0-ring
         */
        std::set<unsigned int> get(unsigned int id_ring);

        // Vertex handle storage
        std::vector<ObjectMesh::VertexHandle> vertex_handles;
        // Taken ?
        OpenMesh::VProp<bool> taken;
        // Association between no_ring and vertex handle
        OpenMesh::VProp<unsigned int> no_ring;
        // Association between valence and vertex handle
        OpenMesh::VProp<unsigned int> valence;
        // Association between angle and half edge
        OpenMesh::HProp<float> angle;
        // Point after deformation
        OpenMesh::VProp<ObjectMesh::Point> deformation;

        void laplacian_deformation_valence();
        void laplacian_deformation_angle();

    private:


        ObjectMesh* obj_mesh;
        unsigned int id_vertex;
        unsigned int nb_ring;
        unsigned int lenght;

        std::vector<std::set<unsigned int>> vertices_rings;

        void clear();
        std::set<ObjectMesh::VertexHandle> ring_from_vertices(
            std::set<ObjectMesh::VertexHandle> vertices_h
        );








};


#endif //MESHMANIPULATOR_RINGMANAGER_H
