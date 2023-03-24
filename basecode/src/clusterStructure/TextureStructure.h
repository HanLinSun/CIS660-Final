#ifndef TEXTURESTRUCTURE_H
#define TEXTURESTRUCTURE_H

#endif // TEXTURESTRUCTURE_H


#include <glm/common.hpp>
#include <glm/vec3.hpp>


#include <rapid_xml/rapidxml_ns.hpp>
#include <svgpp/policy/xml/rapidxml_ns.hpp>
#include <svgpp/svgpp.hpp>

using namespace svgpp;

typedef rapidxml_ns::xml_node<> const * xml_element_t;

typedef
  boost::mpl::set<
    // SVG Structural Elements
    tag::element::svg,
    tag::element::g,
    // SVG Shape Elements
    tag::element::circle,
    tag::element::ellipse,
    tag::element::line,
    tag::element::path,
    tag::element::polygon,
    tag::element::polyline,
    tag::element::rect
  >::type processed_elements_t;


class SVGContext
{
public:

  SVGContext();
  ~SVGContext();
  void path_move_to(double x, double y, tag::coordinate::absolute);

  void path_line_to(double x, double y, tag::coordinate::absolute);

  void path_cubic_bezier_to(
    double x1, double y1,
    double x2, double y2,
    double x, double y,
    tag::coordinate::absolute);

  void path_quadratic_bezier_to(
    double x1, double y1,
    double x, double y,
    tag::coordinate::absolute);

  void path_elliptical_arc_to(
    double rx, double ry, double x_axis_rotation,
    bool large_arc_flag, bool sweep_flag,
    double x, double y,
    tag::coordinate::absolute);

  void path_close_subpath();
  void path_exit();

  void on_enter_element(tag::element::any);
  void on_exit_element();
  void loadSVG(xml_element_t xml_root_element);

private:

};


void loadSvg(xml_element_t xml_root_element)
{
  SVGContext context;
  document_traversal<
    processed_elements<processed_elements_t>,
    processed_attributes<traits::shapes_attributes_by_element>
  >::load_document(xml_root_element, context);
}

