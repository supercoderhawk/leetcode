# -*- coding: utf-8 -*-
class Solution_71_80(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        if not path or path == '/':
            return path

        r_offset = 0
        while len(path) - 1 >= r_offset and path[len(path) - 1 - r_offset] == '/':
            r_offset += 1

        if r_offset:
            path = path[:-r_offset]

        if not path:
            return '/'

        path_segments = path[1:].split('/')
        final_path_segments = []

        for segment in path_segments:
            if segment == '..':
                if final_path_segments:
                    final_path_segments.pop()
            elif segment in {'.', ''}:
                continue
            else:
                final_path_segments.append(segment)

        return '/' + '/'.join(final_path_segments)
