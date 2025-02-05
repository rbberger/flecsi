.. |br| raw:: html

   <br />

.. _overview:

Overview
********

The structure of applications built on top of the FleCSI programming
system assumes three basic types of users. Each of the user types has
their own set of responsibilities that are designed to separate
concerns, and to make sure that development tasks are intuitive and
achievable by the associated user type.

.. tip::

  A single individual may play the role of more than one user type.

The user types are:

* **Core Developer** |br|
  These are users who design, implement, and maintain the core FleCSI
  library. Generally, these users are expert C++ developers who have a
  well-developed understanding of the the low-level design of the FleCSI
  software architecture. These users are generally computer scientists
  with expertise in generic programming techniques, data structure
  design, and optimization.
* **Specialization Developer** |br|
  These are users who adapt the core FleCSI data structures and runtime
  interfaces to create domain-specific interfaces for application
  developers.  These users are required to understand the components of
  the FleCSI interface that can be statically specialized, and must have
  a solid understanding of the runtime interface. Additionally,
  specialization developers are assumed to understand the requirements
  of the application area for which they are designing an interface.
  These users are generally computational scientists with expertise in
  one or more numerical methods areas.
* **Application Developer** |br|
  These users are methods developers or physicists who use a particular
  FleCSI specialization layer to develop and maintain application codes.
  These are the FleCSI end-users, who have expertise in designing and
  implementing numerical methods to solve complicated, multiphysics
  simulation problems.

The source code implementing a FleCSI project will reflect this user
structure: The project will link to the core FleCSI library; The project
will use one or more specializations (These will usually also be
libraries that are linked to by the application.); and, The application
developers will use the core and specialization interfaces to write
their applications.

Documentation
+++++++++++++

FleCSI documentation is primarily directed at *Application* and
*Specialization* developers, and is structured so that these users can
easily skip topics that are out-of-scope for their focus area.
Documentation is split between *prose* (the documentation you are
reading now), and the :doc:`api` that is generated by Doxygen. It
is also divided into *User Guide*, and *Developer Guide* sections.

.. tip::

  Where appropriate we will annotate the documentation to identify the
  intended user audience.

All users should read the *User Guide* documentation and work
through the tutorials, as these describe the runtime, control,
execution, and data models that define the FLeCSI programming model.
Users who are interested in developing FleCSI specializations should
also read the *Developer Guide*. Finally, FleCSI core developers should
read the *Core Guide*.

.. note::

  The *Core Guide* is really only appropriate for developers who are
  creating/maintaining the FleCSI internal repository, or who are
  directly contributing code to the core library.

The release notes advertise new features and bug fixes, announce deprecations, and warn about possible issues when upgrading.

.. toctree::

   news

Namespaces
++++++++++

FlecSI uses C++ namespaces to identify interfaces that are intended for
different user types:

* **flecsi** |br|
  The types and functions defined in the *flecsi* namespace are intended
  for all user types, but are primarily targeted to application
  developers.

.. warning::

  Application developers should **never** use types or methods that are
  not defined in the top-level *flecsi* namespace.

* **flecsi::X** |br|
  The types and functions defined in *flecsi::X* namespaces, where *X*
  is nested within *flecsi*, e.g., *flecsi::topology*, should only be
  used by specialzation and core developers.

* **flecsi::X::Y** |br|
  The types and functions defined in *flecsi::X::Y* namespaces are
  intended for internal FleCSI development only! **Use of any of these
  types or functions outside of the core library is undefined!!!**.

.. vim: set tabstop=2 shiftwidth=2 expandtab fo=cqt tw=72 :
