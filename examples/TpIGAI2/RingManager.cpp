//
// Created by akhaten on 12/14/22.
//

#include "RingManager.hpp"


RingManager::RingManager(MyOpenMesh* mesh)
{
    this->mesh = mesh;
}

RingManager::~RingManager() { }


void RingManager::compute(unsigned int id_vertex, int nb_ring)
{

    this->nb_ring = nb_ring;
    // Clear rings
    this->clear();

    // Intitialization
    this->id_vertex = id_vertex;
    std::set<unsigned int> ring;
    ring.insert(this->id_vertex);
    this->vertices_rings.push_back(ring);
    ring.clear();

    for(unsigned int id_ring = 0; id_ring < nb_ring; ++id_ring){
        // Clear ring
        ring.clear();
        // Take previous ring
        std::set<unsigned int> previous_ring = this->vertices_rings[id_ring];
        // Compute on ring for each vertex in previous ring
        // But there are vertex in previous ring which are in ring
        auto pseudo_ring = this->ring_from_vertices(previous_ring);
        // So delete them
        std::set_difference(
            pseudo_ring.begin(),
            pseudo_ring.end(),
            previous_ring.begin(),
            previous_ring.end(),
            std::inserter(ring, ring.begin())
        );
        // Add the ring
        this->vertices_rings.push_back(ring);
    }

}

std::set<unsigned int> RingManager::get(unsigned int id_ring)
{
    return this->vertices_rings[id_ring];
}

std::set<unsigned int> RingManager::ring_from_vertices(std::set<unsigned int> ids_vertices)
{

    std::set<unsigned int> ring;
    // auto vh = this->mesh->vertex_handle(id_vertex);

    for(unsigned int id_vertex : ids_vertices){

        // Select the good vertex
        MyOpenMesh::VertexIter v_it = this->mesh->vertices_sbegin() + id_vertex;
        for(MyOpenMesh::VertexVertexIter vv_it = this->mesh->vv_iter(*v_it); vv_it.is_valid(); ++vv_it){
            //vv_it->valence();
            ring.insert(vv_it.handle().idx());
        }

    }

    return ring;

}

void RingManager::clear()
{
    this->vertices_rings.clear();
    this->nb_ring = 0;
}
