#include <meshaccess.hpp>


namespace ngcomp
{
  void ExploreMesh (shared_ptr<MeshAccess> mesh)
  {
    cout << "num verts: " << mesh->GetNV() << endl;
    cout << "num edges: " << mesh->GetNEdges() << endl;
    cout << "num faces: " << mesh->GetNFaces() << endl;

    cout << "Vol elements: " << mesh->GetNE(VOL) << endl;
    cout << "Bnd elements: " << mesh->GetNE(BND) << endl;

    cout << endl << "vertex to element:" << endl;
    for (auto v : Range(mesh->GetNV()))
      {
        cout << "V" << v << " -> ";
        for (auto el : mesh->GetVertexElements(v,VOL))
          cout << el << " ";
        cout << endl;
      }
  }
}
