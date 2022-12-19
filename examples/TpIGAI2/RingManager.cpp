
#include "RingManager.hpp"

//#include <OpenMesh/Core/Mesh/SmartHandles.hh>
#include <eigen3/Eigen/Dense>


RingManager::RingManager(ObjectMesh* obj_mesh):
    taken(*obj_mesh),
    no_ring(*obj_mesh),
    valence(*obj_mesh),
    angle(*obj_mesh),
    deformation(*obj_mesh)
{

    this->obj_mesh = obj_mesh;
    this->clear();



}

RingManager::~RingManager() { }


void RingManager::compute(unsigned int id_vertex, unsigned int nb_ring)
{

    this->clear();
    this->nb_ring = nb_ring;
    ObjectMesh::VertexHandle vh = this->obj_mesh->vertex_handle(id_vertex);
    this->vertex_handles.push_back(vh);
    this->no_ring[vh] = 0;
    this->taken[vh] = true;

    std::set<ObjectMesh::VertexHandle> ring_current;
    ring_current.insert(vh);

    for(unsigned int id_ring = 0; id_ring < nb_ring; ++id_ring){


        auto pseudo_ring = this->ring_from_vertices(ring_current);

        std::set<ObjectMesh::VertexHandle> ring_truly;
        for(ObjectMesh::VertexHandle vh_ring : pseudo_ring){
            if(!(this->taken[vh_ring])){
                this->vertex_handles.push_back(vh_ring);
                this->no_ring[vh_ring] = id_ring+1;
                this->taken[vh_ring] = true;
                ring_truly.insert(vh_ring);
            }

        }

        ring_current = ring_truly;

    }


    /*this->nb_ring = nb_ring;
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

        this->lenght += ring.size();
        // Add the ring
        this->vertices_rings.push_back(ring);
    }*/

}

std::set<unsigned int> RingManager::get(unsigned int id_ring)
{
    return this->vertices_rings[id_ring];
}

std::set<ObjectMesh::VertexHandle> RingManager::ring_from_vertices(
        std::set<ObjectMesh::VertexHandle> vertices_h
){

    std::set<ObjectMesh::VertexHandle> ring;

    for(ObjectMesh::VertexHandle vh : vertices_h){

        // Select center of ring
        ObjectMesh::Point vh_point = this->obj_mesh->point(vh);
        // Conversion : ObjectMesh::Point -> glm::vec3
        glm::vec3 vh_glm = glm::vec3(vh_point[0], vh_point[1], vh_point[2]);

        for(ObjectMesh::VertexHandle vvh : this->obj_mesh->vv_range(vh)){

            if(!(this->taken[vvh])) {

                ring.insert(vvh);

                // Smart half edge handle between two vertex
                //      vh -> vvh
                OpenMesh::SmartHalfedgeHandle sheh = this->obj_mesh->find_halfedge(vh, vvh);
                //      vvh -> vh
                OpenMesh::SmartHalfedgeHandle sheh_opp = sheh.opp();


                // Vertex opposite of
                // sheh
                //auto vh_sheh = this->obj_mesh->opposite_vh(sheh);
                auto vh_sheh = sheh.next().to();
                // sheh opp
                //auto vh_sheh_opp = this->obj_mesh->opposite_vh(sheh.opp());
                auto vh_sheh_opp = sheh.opp().next().to();

                // Select Points
                ObjectMesh::Point vvh_point = this->obj_mesh->point(vvh);
                ObjectMesh::Point p0 = this->obj_mesh->point(vh_sheh);
                ObjectMesh::Point p1 = this->obj_mesh->point(vh_sheh_opp);


                // Conversion : ObjectMesh::Point -> glm::vec3
                glm::vec3 vvh_glm = glm::vec3(vvh_point[0], vvh_point[1], vvh_point[2]);
                glm::vec3 p0_glm = glm::vec3(p0[0], p0[1], p0[2]);
                glm::vec3 p1_glm = glm::vec3(p1[0], p1[1], p1[2]);


                /*std::cout << vh_point-p0 << std::endl;
                std::cout << vvh_point-p0 << std::endl;
                std::cout << p1 << std::endl;*/

                // Compute vectors
                glm::vec3 vec01 = glm::normalize(vh_glm-p0_glm);
                glm::vec3 vec02 = glm::normalize(vvh_glm-p0_glm);
                glm::vec3 vec11 = glm::normalize(vh_glm-p1_glm);
                glm::vec3 vec12 = glm::normalize(vvh_glm-p1_glm);

                /*std::cout << vec01.x << " ; " << vec01.y << " ; " << vec01.z << std::endl;
                std::cout << vec02.x << " ; " << vec02.y << " ; " << vec02.z << std::endl;*/

                // Compute angle
                // a.b = ||a|| * ||b|| * cos(theta)
                // cos(theta) = (a.b) / (||a|| * ||b||)
                // glm::normalize => ||a|| = ||b|| = 1
                // So, cos(theta) = a.b
                // theta = acos( (a.b) / (||a|| * ||b||) ) = acos(a.b)

                // Angle opposite to sheh
                float cos_theta0 = glm::dot(vec01, vec02);
                // this->angle[sheh] = cos_theta0;
                // Angle opposite to sheh_opp
                float cos_theta1 = glm::dot(vec11, vec12);
                // this->angle[sheh_opp] = cos_theta1;

                //std::cout << cos_theta0 << " ; " << cos_theta1 << std::endl;

                //double theta0 = acos(cos_theta0);
                //double theta1 = acos(cos_theta1);

                //std::cout << theta0 << " ; " << theta1 << std::endl;

                this->angle[sheh] = acos((double)cos_theta0);
                this->angle[sheh_opp] = acos((double)cos_theta1);

            }

            ++this->valence[vh];

        }
    }

    return ring;

}

void RingManager::clear()
{
    /*this->vertices_rings.clear();
    this->nb_ring = 0;
    this->lenght = 0;*/

    this->vertex_handles.clear();

    for(ObjectMesh::VertexHandle vh : this->obj_mesh->vertices()){
        this->taken[vh] = false;
        this->no_ring[vh] = -1;
        this->valence[vh] = 0;
        this->deformation[vh] = ObjectMesh::Point(0.0f, 0.0f, 0.0f);
    }

    for(ObjectMesh::HalfedgeHandle hh : this->obj_mesh->halfedges())
        this->angle[hh] = -1.0f;

}

void RingManager::laplacian_deformation_valence()
{

    unsigned int n = this->vertex_handles.size();

    // i < nb_ring :
    //      i == j -> -1.0f
    //      half_edge(i, j) is not valid -> 0.0f
    //      half_edge(i, j) is valid -> weight(i, j)
    // i == nb_ring -> boundary condition :
    //

    Eigen::MatrixXf m(n, n);

    // i < nb_ring -> 0.0f
    // i == nb_ring -> 1.0f
    Eigen::MatrixXf b(n, 1);


    // weight(i, j) = valence(i)
    // weight(i, j) = cos(alpha(i, j)) + cos(alpha(i, j))

    unsigned int i;


    for(i = 0; i < n; ++i){

        ObjectMesh::VertexHandle vh_i = this->vertex_handles[i];

        if(this->no_ring[vh_i] == this->nb_ring){
            std::cout << this->no_ring[vh_i] << std::endl;
            break;
        }

        b(i, 0) = (i == 0) ? 1.0f : 0.0f;

        for(unsigned int j = 0; j < n; ++j){

            ObjectMesh::VertexHandle vh_j = this->vertex_handles[j];

            if(vh_i == vh_j){
                m(i, j) = -1.0f;
            }else{

                OpenMesh::SmartHalfedgeHandle sheh = this->obj_mesh->find_halfedge(vh_i, vh_j);
                if(!(sheh.is_valid())){
                    // vh_i and vh_j is not adjacent
                    m(i, j) = 0.0f;
                }else{
                    // vh_i and vh_j adjacent
                    m(i, j) = 1.0f/(float)this->valence[vh_i];
                }

            }

        }

    }

    unsigned int mid_boundary = (n-i)/2;
    mid_boundary += i;

    //std::cout << i << " ; " << mid_boundary << " ; " << n << std::endl;

    float sum = m(i-1, i-1);

    for(; i < n; ++i){

        ObjectMesh::VertexHandle vh_i = this->vertex_handles[i];
        //b(i, 0) = (i < mid_boundary) ? 0.0f : 1.0f;
        b(i, 0) = 0.0f;
        // std::cout << this->nb_ring << " ; " << this->no_ring[vh_i] << std::endl;
        for(unsigned int j = 0; j < n; ++j){

            ObjectMesh::VertexHandle vh_j = this->vertex_handles[j];

            if(vh_i == vh_j){
                m(i, j) = 1.0f;
                //m(i, j) = -sum;
            }else{
                m(i, j) = 0.0f;
            }

        }

    }


    auto res = m.inverse() * b;

    for(i = 0; i < n; ++i) {
        ObjectMesh::VertexHandle vh_i = this->vertex_handles[i];
        std::cout << this->no_ring[vh_i] << " ; " << std::abs(res(i, 0)) << std::endl;
        this->deformation[vh_i] = res(i, 0) * ObjectMesh::Point(0.0f, 0.01f, 0.0f);
        //this->deformation[vh_i] = std::abs(res(i, 0)) * ObjectMesh::Point(0.0f, 0.01f, 0.0f);
    }



}

void RingManager::laplacian_deformation_angle()
{

    unsigned int n = this->vertex_handles.size();

    // i < nb_ring :
    //      i == j -> -1.0f
    //      half_edge(i, j) is not valid -> 0.0f
    //      half_edge(i, j) is valid -> weight(i, j)
    // i == nb_ring -> boundary condition :
    //

    Eigen::MatrixXf m(n, n);

    // i < nb_ring -> 0.0f
    // i == nb_ring -> 1.0f
    Eigen::MatrixXf b(n, 1);


    // weight(i, j) = valence(i)
    // weight(i, j) = cos(alpha(i, j)) + cos(alpha(i, j))

    unsigned int i;


    for(i = 0; i < n; ++i){

        ObjectMesh::VertexHandle vh_i = this->vertex_handles[i];

        if(this->no_ring[vh_i] == this->nb_ring){
            std::cout << this->no_ring[vh_i] << std::endl;
            break;
        }

        b(i, 0) = (i == 0) ? 1.0f : 0.0f;

        for(unsigned int j = 0; j < n; ++j){

            ObjectMesh::VertexHandle vh_j = this->vertex_handles[j];

            if(vh_i == vh_j){
                //std::cout << "vh_i == vh_j" << std::endl;
                //m(i, j) = -1.0f;
                // Nothing
            }else{

                OpenMesh::SmartHalfedgeHandle sheh = this->obj_mesh->find_halfedge(vh_i, vh_j);
                if(!(sheh.is_valid())){
                    // vh_i and vh_j is not adjacent
                    m(i, j) = 0.0f;
                }else{
                    float alpha = 0.25f;
                    // vh_i and vh_j adjacent
                    double cos_theta0 = cos((double)this->angle[sheh]);
                    double cos_theta1 = cos((double)this->angle[sheh.opp()]);
                    m(i, j) = alpha * (cos_theta0 + cos_theta1);
                    m(i, i) -= alpha * (cos_theta0 + cos_theta1);
                }

            }

        }

    }

    for(; i < n; ++i){
        b(i, 0) = 0.0f;
        for(unsigned int j = 0; j < n; ++j){
            m(i, j) = (i == j) ? 1.0f : 0.0f;
        }
    }

    auto res = m.inverse() * b;

    for(i = 0; i < n; ++i) {
        ObjectMesh::VertexHandle vh_i = this->vertex_handles[i];
        this->deformation[vh_i] = std::abs(res(i, 0)) * ObjectMesh::Point(0.0f, 0.01f, 0.0f);
    }



}
